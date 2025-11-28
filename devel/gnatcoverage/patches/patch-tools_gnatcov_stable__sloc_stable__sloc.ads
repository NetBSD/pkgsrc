$NetBSD: patch-tools_gnatcov_stable__sloc_stable__sloc.ads,v 1.1 2025/11/28 21:03:12 dkazankov Exp $

Create source file for stable_sloc package

--- /dev/null
+++ tools/gnatcov/stable_sloc/stable_sloc.ads
@@ -0,0 +1,119 @@
+with Ada.Strings.Unbounded; use Ada.Strings.Unbounded;
+with Ada.Strings.Unbounded.Hash;
+with Ada.Containers.Vectors;
+with Ada.Containers.Hashed_Maps;
+with GNATCOLL.VFS; use GNATCOLL.VFS;
+with TOML; use TOML;
+
+package Stable_Sloc is
+
+   type Sloc is record
+      Line, Column : Natural;
+   end record;
+
+   function Image (S : Sloc) return String;
+
+   type Sloc_Span is record
+      Start_Sloc, End_Sloc : Sloc;
+   end record;
+
+   function Image (S : Sloc_Span) return String;
+
+   type Entry_Type is record
+      Annotations : TOML_Value;
+      Kind : Unbounded_UTF8_String;
+      File : Virtual_File;
+      Location : Sloc_Span;
+      File_Prefix : Unbounded_UTF8_String;
+   end record;
+
+   type Entry_View is access all Entry_Type;
+
+   No_Entry_View : Entry_View := null;
+
+   type Entry_DB is private;
+
+   type Match_Result (Success : Boolean := True) is record
+      case Success is
+         when False =>
+            Diagnostic  : Unbounded_UTF8_String;
+         when True  =>
+            File        : Virtual_File;
+            Identifier  : Unbounded_UTF8_String;
+            Location    : Sloc_Span;
+            Annotation  : TOML_Value;
+      end case;
+   end record;
+
+   package Match_Result_Vectors is new Ada.Containers.Vectors (Index_Type => Positive, Element_Type => Match_Result);
+   subtype Match_Result_Vec is Match_Result_Vectors.Vector;
+
+   function Is_Empty (DB : Entry_DB) return Boolean;
+
+   subtype Load_Diagnostic is Unbounded_UTF8_String;
+   type Load_Diagnostic_Arr is array (Positive range <>) of Load_Diagnostic;
+
+   function Add_Or_Update_Entry
+     (DB          : in out Entry_DB;
+      Identifier  : Unbounded_UTF8_String;
+      Annotation  : TOML_Value;
+      Kind        : Unbounded_UTF8_String;
+      File        : Virtual_File;
+      Span        : Sloc_Span;
+      File_Prefix : Unbounded_UTF8_String) return Load_Diagnostic_Arr;
+
+   procedure Replace_Entry
+     (Target_DB : in out Entry_DB;
+      Source_DB : Entry_DB;
+      Target_Id : Unbounded_UTF8_String;
+      Source_Id : Unbounded_UTF8_String);
+
+   function Query_Entry
+     (DB        : Entry_DB;
+      Identifier: Unbounded_UTF8_String) return Entry_View;
+
+   procedure Delete_Entry
+     (DB : in out Entry_DB;
+      Identifier : Unbounded_UTF8_String);
+
+   procedure Iterate_Entries
+     (DB : Entry_DB;
+      Action : access procedure (Identifier : Unbounded_UTF8_String; Entr : Entry_View));
+
+   procedure Clear_DB (DB : in out Entry_DB);
+
+   function Load_Entries
+     (File  : Virtual_File;
+      DB    : in out Entry_DB) return Load_Diagnostic_Arr;
+
+   procedure Write_Entries
+     (DB   : Entry_DB;
+      File : Virtual_File);
+
+   function Match_Entries
+     (Files         : File_Array;
+      DB            : Entry_DB;
+      Purpose_Prefix: String) return Match_Result_Vec;
+      
+   procedure Sort (Match_Result : in out Match_Result_Vec);
+
+   function Format_Diagnostic
+     (Diagnostic : Load_Diagnostic) return String;
+
+private
+
+   use Ada.Containers;
+
+   package Entry_Maps is new Ada.Containers.Hashed_Maps (
+      Key_Type => Unbounded_UTF8_String,
+      Element_Type => Entry_Type,
+      Hash => Ada.Strings.Unbounded.Hash,
+      Equivalent_Keys => "=");
+
+   use Entry_Maps;
+
+   type Entry_DB is record
+      Entries : Map;
+   end record;
+
+end Stable_Sloc;
