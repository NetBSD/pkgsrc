$NetBSD: patch-tools_gnatcov_stable__sloc_stable__sloc.adb,v 1.1 2025/11/28 21:03:12 dkazankov Exp $

Create source file for stable_sloc package

--- /dev/null
+++ tools/gnatcov/stable_sloc/stable_sloc.adb
@@ -0,0 +1,222 @@
+with Ada.Exceptions; use Ada.Exceptions;
+with Ada.Text_IO; use Ada.Text_IO;
+with TOML.File_IO; use TOML.File_IO;
+
+package body Stable_Sloc is
+
+   function Image (S : Sloc) return String
+   is
+   begin
+      return Natural'Image (S.Line) & ":" & Natural'Image (S.Column);
+   end;
+
+   function Image (S : Sloc_Span) return String
+   is
+   begin
+      return Image (S.Start_Sloc) & ".." & Image (S.End_Sloc);
+   end;
+
+   function Is_Empty
+     (DB        : Entry_DB) return Boolean is
+   begin
+      return DB.Entries.Is_Empty;
+   end Is_Empty;
+
+   function Add_Or_Update_Entry
+     (DB          : in out Entry_DB;
+      Identifier  : Unbounded_UTF8_String;
+      Annotation  : TOML_Value;
+      Kind        : Unbounded_UTF8_String;
+      File        : Virtual_File;
+      Span        : Sloc_Span;
+      File_Prefix : Unbounded_UTF8_String) return Load_Diagnostic_Arr
+   is
+   begin
+      DB.Entries.Include (Identifier, Entry_Type'(Annotations => Annotation, Kind => Kind, File => File,
+         Location => Span, File_Prefix => File_Prefix));
+      return (1..1 => Null_Unbounded_String);
+   end Add_Or_Update_Entry;
+
+   procedure Replace_Entry
+     (Target_DB : in out Entry_DB;
+      Source_DB : Entry_DB;
+      Target_Id : Unbounded_UTF8_String;
+      Source_Id : Unbounded_UTF8_String) is
+   begin
+      Target_DB.Entries.Replace (Target_Id, Source_DB.Entries.Element (Source_Id));
+   end Replace_Entry;
+
+   function Query_Entry
+     (DB        : Entry_DB;
+      Identifier: Unbounded_UTF8_String) return Entry_View is
+      C : Cursor := DB.Entries.Find (Identifier);
+   begin
+      if C = No_Element then
+         return No_Entry_View;
+      else
+         return DB.Entries.Constant_Reference (C).Element;
+      end if;
+   end Query_Entry;
+
+   procedure Delete_Entry
+     (DB : in out Entry_DB;
+      Identifier : Unbounded_UTF8_String) is
+   begin
+      DB.Entries.Exclude (Identifier);
+   end Delete_Entry;
+
+   procedure Iterate_Entries
+     (DB : Entry_DB;
+      Action : access procedure (Identifier : Unbounded_UTF8_String; Entr : Entry_View))
+   is
+      procedure Process (Position: Cursor)
+      is
+      begin
+         Action (Key (Position), DB.Entries.Constant_Reference (Position).Element);
+      end;
+   begin
+      DB.Entries.Iterate (Process'Access);
+   end Iterate_Entries;
+
+   procedure Clear_DB (DB : in out Entry_DB) is
+   begin
+      DB.Entries.Clear;
+   end Clear_DB;
+
+   function Load_Entries
+     (File  : Virtual_File;
+      DB    : in out Entry_DB) return Load_Diagnostic_Arr
+   is
+      Result : Read_Result := Load_File (+ (Full_Name (File)));
+   begin
+      if Result.Success then
+         declare
+            Identifier  : Unbounded_UTF8_String;
+            Annotations : TOML_Value;
+            Kind        : Unbounded_UTF8_String;
+            File        : Virtual_File;
+            Span_V      : TOML_Value;
+            Start_Sloc  : Source_Location;
+            End_Sloc    : Source_Location;
+            File_Prefix : Unbounded_UTF8_String;
+            Diag_Arr    : Load_Diagnostic_Arr (1..Result.Value.Length);
+            V : TOML_Value;
+         begin
+            for I in 1..Result.Value.Length loop
+               V := Result.Value.Item (I);
+               Identifier  := V.Get ("Identifier").As_Unbounded_String;
+               Annotations := V.Get ("Annotations");
+               Kind        := V.Get ("Kind").As_Unbounded_String;
+               File        := Create (Filesystem_String (V.Get ("File").As_String));
+               Span_V      := V.Get ("Location");
+               Start_Sloc  := Location (Span_V.Get ("Start_Sloc"));
+               End_Sloc    := Location (Span_V.Get ("End_Sloc"));
+               File_Prefix := V.Get ("File_Prefix").As_Unbounded_String;
+               declare
+                  Diag : Load_Diagnostic_Arr := Add_Or_Update_Entry (
+                     DB, Identifier, Annotations, Kind, File, (
+                        Start_Sloc => (Line => Start_Sloc.Line, Column => Start_Sloc.Column),
+                        End_Sloc => (Line => End_Sloc.Line, Column => End_Sloc.Column)
+                     ),
+                     File_Prefix);
+               begin
+                  if Diag'Length = 0 then
+                     Diag_Arr (I) := Null_Unbounded_String;
+                  else
+                     Diag_Arr (I) := Diag (Diag'First);
+                  end if;
+               end;
+            end loop;
+            return Diag_Arr;
+         end;
+      else
+         return (1..1 => Result.Message);
+      end if;
+   end Load_Entries;
+
+   procedure Write_Entries
+     (DB   : Entry_DB;
+      File : Virtual_File) is
+      A : TOML_Value := Create_Array;
+      procedure Fill_Array (Position: Cursor)
+      is
+         V : TOML_Value;
+         E : Constant_Reference_Type := DB.Entries.Constant_Reference (Position);
+         Location, Start_Sloc, End_Sloc : TOML_Value;
+      begin
+         Set (V, "Identifier", Create_String (Key (Position)));
+         Set (V, "Annotations", E.Annotations);
+         Set (V, "Kind", Create_String (E.Kind));
+         Set (V, "File", Create_String (+Full_Name (E.File)));
+         Set (Start_Sloc, "Line", Create_Integer (Any_Integer (E.Location.Start_Sloc.Line)));
+         Set (Start_Sloc, "Column", Create_Integer (Any_Integer (E.Location.Start_Sloc.Column)));
+         Set (Location, "Start_Sloc", Start_Sloc);
+         Set (End_Sloc, "Line", Create_Integer (Any_Integer (E.Location.End_Sloc.Line)));
+         Set (End_Sloc, "Column", Create_Integer (Any_Integer (E.Location.End_Sloc.Column)));
+         Set (Location, "End_Sloc", End_Sloc);
+         Set (V, "Location", Location);
+         Set (V, "File_Prefix", Create_String (E.File_Prefix));
+         Append (A, V);
+      end;
+      F : File_Type;
+   begin
+      DB.Entries.Iterate (Fill_Array'Access);
+      begin
+         Open (F, Out_File, +Full_Name (File));
+      exception
+         when E : Name_Error | Use_Error =>
+            Create (F, Out_File, +Full_Name (File));
+      end;
+      Dump_To_File (A, F);
+      Close (F);
+   end Write_Entries;
+
+   function Match_Entries
+     (Files         : File_Array;
+      DB            : Entry_DB;
+      Purpose_Prefix: String) return Match_Result_Vec is
+      
+      Result : Match_Result_Vec;
+      
+      procedure Process (Position: Cursor)
+      is
+         EV : Constant_Reference_Type := DB.Entries.Constant_Reference (Position);
+      begin
+         if To_String (EV.File_Prefix) = Purpose_Prefix then
+            for F of Files loop
+               if EV.File = F then
+                  Result.Append (Match_Result'(
+                     Success => True,
+                     File => EV.File,
+                     Identifier => Key (Position),
+                     Location => EV.Location,
+                     Annotation => EV.Annotations));
+               end if;
+            end loop;
+         end if;
+      end;
+   begin
+      DB.Entries.Iterate (Process'Access);
+      if Result.Length = 0 then
+         Result.Append (Match_Result'(
+            Success => False,
+            Diagnostic => Null_Unbounded_String)
+         );
+      end if;
+      return Result;
+   end Match_Entries;
+
+   procedure Sort (Match_Result : in out Match_Result_Vec)
+   is
+   begin
+      null;
+   end;
+
+   function Format_Diagnostic
+     (Diagnostic : Load_Diagnostic) return String
+   is
+   begin
+      return To_String (Diagnostic);
+   end;
+
+end Stable_Sloc;
