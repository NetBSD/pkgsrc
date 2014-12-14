$NetBSD: patch-ext_tk_lib_tkextlib_tkimg_raw.rb,v 1.1 2014/12/14 14:00:06 taca Exp $

* Add tcl/tk 8.6 support.

--- /dev/null	2014-12-14 12:14:32.000000000 +0000
+++ ext/tk/lib/tkextlib/tkimg/raw.rb
@@ -0,0 +1,33 @@
+#
+#  TkImg - format 'Raw Data'
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
+# TkPackage.require('img::raw', '1.4')
+TkPackage.require('img::raw')
+
+module Tk
+  module Img
+    module Raw
+      PACKAGE_NAME = 'img::raw'.freeze
+      def self.package_name
+        PACKAGE_NAME
+      end
+
+      def self.package_version
+        begin
+          TkPackage.require('img::raw')
+        rescue
+          ''
+        end
+      end
+    end
+  end
+end
