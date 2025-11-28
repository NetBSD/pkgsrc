$NetBSD: patch-tools_gnatcov_stable__sloc_stable__sloc-toml__utils.adb,v 1.1 2025/11/28 21:03:12 dkazankov Exp $

Create source file for stable_sloc package

--- /dev/null
+++ tools/gnatcov/stable_sloc/stable_sloc-toml_utils.adb
@@ -0,0 +1,25 @@
+package body Stable_Sloc.TOML_Utils is
+
+   function Get_Or_Null
+     (Annot : TOML_Value; Field : String) return Unbounded_String
+   is
+   begin
+      if Annot.Has (Field) then
+         return Annot.As_Unbounded_String;
+      else
+         return Null_Unbounded_String;
+      end if;
+   end Get_Or_Null;
+
+   function Get_Or_Default
+     (Annot : TOML_Value; Field : String; Default : Boolean) return Boolean
+   is
+   begin
+      if Annot.Has (Field) then
+         return Annot.As_Boolean;
+      else
+         return Default;
+      end if;
+   end Get_Or_Default;
+
+end Stable_Sloc.TOML_Utils;
