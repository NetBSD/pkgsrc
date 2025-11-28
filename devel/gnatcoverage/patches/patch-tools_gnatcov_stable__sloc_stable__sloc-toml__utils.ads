$NetBSD: patch-tools_gnatcov_stable__sloc_stable__sloc-toml__utils.ads,v 1.1 2025/11/28 21:03:12 dkazankov Exp $

Create source file for stable_sloc package

--- /dev/null
+++ tools/gnatcov/stable_sloc/stable_sloc-toml_utils.ads
@@ -0,0 +1,12 @@
+with Ada.Strings.Unbounded; use Ada.Strings.Unbounded;
+with TOML; use TOML;
+
+package Stable_Sloc.TOML_Utils is
+
+   function Get_Or_Null
+     (Annot : TOML_Value; Field : String) return Unbounded_String;
+
+   function Get_Or_Default
+     (Annot : TOML_Value; Field : String; Default : Boolean) return Boolean;
+
+end Stable_Sloc.TOML_Utils;
