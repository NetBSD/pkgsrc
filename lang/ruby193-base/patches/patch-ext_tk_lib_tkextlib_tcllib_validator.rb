$NetBSD: patch-ext_tk_lib_tkextlib_tcllib_validator.rb,v 1.1 2014/12/14 13:59:53 taca Exp $

* Add tcl/tk 8.6 support.

--- /dev/null	2014-10-27 05:13:29.000000000 +0000
+++ ext/tk/lib/tkextlib/tcllib/validator.rb
@@ -0,0 +1,65 @@
+#
+#  tkextlib/tcllib/validator.rb
+#                               by Hidetoshi NAGAI (nagai@ai.kyutech.ac.jp)
+#
+#   * Part of tcllib extension
+#   * Provides a unified validation API
+#
+
+require 'tk'
+require 'tkextlib/tcllib.rb'
+
+# TkPackage.require('widget::validator', '0.1')
+TkPackage.require('widget::validator')
+
+module Tk::Tcllib
+  module Validator
+    PACKAGE_NAME = 'widget::validator'.freeze
+    def self.package_name
+      PACKAGE_NAME
+    end
+
+    def self.package_version
+      begin
+        TkPackage.require('widget::validator')
+      rescue
+        ''
+      end
+    end
+  end
+end
+
+module Tk::Tcllib::Validator
+  extend TkCore
+
+  def self.attach(widget, color, cmd=Proc.new)
+    tk_call_without_enc('::widget::validator', 'attach', widget, color, cmd)
+    nil
+  end
+
+  def self.detach(widget)
+    tk_call_without_enc('::widget::validator', 'detach', widget)
+    nil
+  end
+
+  def self.validate(widget)
+    tk_call_without_enc('::widget::validator', 'validate', widget)
+    nil
+  end
+
+  def attach_validator(color, cmd=Proc.new)
+    tk_call_without_enc('::widget::validator', 'attach', @path, color, cmd)
+    self
+  end
+
+  def detach_validator(color, cmd=Proc.new)
+    tk_call_without_enc('::widget::validator', 'detach', @path)
+    self
+  end
+
+  def invoke_validator(color, cmd=Proc.new)
+    tk_call_without_enc('::widget::validator', 'validate', @path)
+    self
+  end
+  alias validate_validator invoke_validator
+end
