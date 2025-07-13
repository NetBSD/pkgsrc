$NetBSD: patch-ext_win32_lib_win32_resolv.rb,v 1.1 2025/07/13 15:39:54 taca Exp $

Update resolv gem to 0.6.2.

--- ext/win32/lib/win32/resolv.rb.orig	2025-05-14 03:11:06.000000000 +0000
+++ ext/win32/lib/win32/resolv.rb
@@ -4,13 +4,8 @@
 
 =end
 
-require 'win32/registry'
-
 module Win32
   module Resolv
-    API = Registry::API
-    Error = Registry::Error
-
     def self.get_hosts_path
       path = get_hosts_dir
       path = File.expand_path('hosts', path)
@@ -47,89 +42,103 @@ module Win32
 # Windows NT
 #====================================================================
   module Resolv
-    module SZ
-      refine Registry do
-        # ad hoc workaround for broken registry
-        def read_s(key)
-          type, str = read(key)
-          unless type == Registry::REG_SZ
-            warn "Broken registry, #{name}\\#{key} was #{Registry.type2name(type)}, ignored"
-            return String.new
+    begin
+      require 'win32/registry'
+      module SZ
+        refine Registry do
+          # ad hoc workaround for broken registry
+          def read_s(key)
+            type, str = read(key)
+            unless type == Registry::REG_SZ
+              warn "Broken registry, #{name}\\#{key} was #{Registry.type2name(type)}, ignored"
+              return String.new
+            end
+            str
           end
-          str
         end
       end
+      using SZ
+    rescue LoadError
+      require "open3"
     end
-    using SZ
 
     TCPIP_NT = 'SYSTEM\CurrentControlSet\Services\Tcpip\Parameters'
 
     class << self
       private
       def get_hosts_dir
-        Registry::HKEY_LOCAL_MACHINE.open(TCPIP_NT) do |reg|
-          reg.read_s_expand('DataBasePath')
-        end
+        get_item_property(TCPIP_NT, 'DataBasePath', expand: true)
       end
 
       def get_info
         search = nil
         nameserver = get_dns_server_list
-        Registry::HKEY_LOCAL_MACHINE.open(TCPIP_NT) do |reg|
-          begin
-            slist = reg.read_s('SearchList')
-            search = slist.split(/,\s*/) unless slist.empty?
-          rescue Registry::Error
-          end
 
-          if add_search = search.nil?
-            search = []
-            begin
-              nvdom = reg.read_s('NV Domain')
-              unless nvdom.empty?
-                @search = [ nvdom ]
-                if reg.read_i('UseDomainNameDevolution') != 0
-                  if /^\w+\./ =~ nvdom
-                    devo = $'
-                  end
-                end
+        slist = get_item_property(TCPIP_NT, 'SearchList')
+        search = slist.split(/,\s*/) unless slist.empty?
+
+        if add_search = search.nil?
+          search = []
+          nvdom = get_item_property(TCPIP_NT, 'NV Domain')
+
+          unless nvdom.empty?
+            @search = [ nvdom ]
+            udmnd = get_item_property(TCPIP_NT, 'UseDomainNameDevolution').to_i
+            if udmnd != 0
+              if /^\w+\./ =~ nvdom
+                devo = $'
               end
-            rescue Registry::Error
             end
           end
+        end
 
-          reg.open('Interfaces') do |h|
-            h.each_key do |iface, |
-              h.open(iface) do |regif|
-                next unless ns = %w[NameServer DhcpNameServer].find do |key|
-                  begin
-                    ns = regif.read_s(key)
-                  rescue Registry::Error
-                  else
-                    break ns.split(/[,\s]\s*/) unless ns.empty?
-                  end
+        ifs = if defined?(Win32::Registry)
+                Registry::HKEY_LOCAL_MACHINE.open(TCPIP_NT + '\Interfaces') do |reg|
+                  reg.keys
+                rescue Registry::Error
+                  []
                 end
-                next if (nameserver & ns).empty?
+              else
+                cmd = "Get-ChildItem 'HKLM:\\#{TCPIP_NT}\\Interfaces' | ForEach-Object { $_.PSChildName }"
+                output, _ = Open3.capture2('powershell', '-Command', cmd)
+                output.split(/\n+/)
+              end
 
-                if add_search
-                  begin
-                    [ 'Domain', 'DhcpDomain' ].each do |key|
-                      dom = regif.read_s(key)
-                      unless dom.empty?
-                        search.concat(dom.split(/,\s*/))
-                        break
-                      end
-                    end
-                  rescue Registry::Error
-                  end
-                end
+        ifs.each do |iface|
+          next unless ns = %w[NameServer DhcpNameServer].find do |key|
+            ns = get_item_property(TCPIP_NT + '\Interfaces' + "\\#{iface}", key)
+            break ns.split(/[,\s]\s*/) unless ns.empty?
+          end
+
+          next if (nameserver & ns).empty?
+
+          if add_search
+            [ 'Domain', 'DhcpDomain' ].each do |key|
+              dom = get_item_property(TCPIP_NT + '\Interfaces' + "\\#{iface}", key)
+              unless dom.empty?
+                search.concat(dom.split(/,\s*/))
+                break
               end
             end
           end
-          search << devo if add_search and devo
         end
+        search << devo if add_search and devo
         [ search.uniq, nameserver.uniq ]
       end
+
+      def get_item_property(path, name, expand: false)
+        if defined?(Win32::Registry)
+          Registry::HKEY_LOCAL_MACHINE.open(path) do |reg|
+            expand ? reg.read_s_expand(name) : reg.read_s(name)
+          rescue Registry::Error
+            ""
+          end
+        else
+          cmd = "Get-ItemProperty -Path 'HKLM:\\#{path}' -Name '#{name}' -ErrorAction SilentlyContinue | Select-Object -ExpandProperty '#{name}'"
+          output, _ = Open3.capture2('powershell', '-Command', cmd)
+          output.strip
+        end
+      end
     end
   end
 end
