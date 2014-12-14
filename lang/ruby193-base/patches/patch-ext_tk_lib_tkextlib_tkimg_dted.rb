$NetBSD: patch-ext_tk_lib_tkextlib_tkimg_dted.rb,v 1.1 2014/12/14 13:59:53 taca Exp $

* Add tcl/tk 8.6 support.

--- /dev/null	2014-10-27 05:15:45.000000000 +0000
+++ ext/tk/lib/tkextlib/tkimg/dted.rb
@@ -0,0 +1,33 @@
+#
+#  TkImg - format 'DTED'
+#                               by Hidetoshi NAGAI (nagai@ai.kyutech.ac.jp)
+#
+require 'tk'
+
+# call setup script for general 'tkextlib' libraries
+require 'tkextlib/setup.rb'
+
+# call setup script
+require 'tkextlib/tkimg/setup.rb'
+
+# TkPackage.require('img::dted', '1.4')
+TkPackage.require('img::dted')
+
+module Tk
+  module Img
+    module DTED
+      PACKAGE_NAME = 'img::dted'.freeze
+      def self.package_name
+        PACKAGE_NAME
+      end
+
+      def self.package_version
+        begin
+          TkPackage.require('img::dted')
+        rescue
+          ''
+        end
+      end
+    end
+  end
+end
