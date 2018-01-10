$NetBSD: patch-myocamlbuild.ml,v 1.1 2018/01/10 16:19:01 jaapb Exp $

Regenerated Oasis files (don't compile with 4.06)
--- myocamlbuild.ml.orig	2015-09-02 21:53:11.000000000 +0000
+++ myocamlbuild.ml
@@ -1,19 +1,12 @@
 (* OASIS_START *)
-(* DO NOT EDIT (digest: 5a9a2168dcb86db37476d58b8c0e25b3) *)
+(* DO NOT EDIT (digest: 9bd78b75e5e0b109a1abb54bf043b292) *)
 module OASISGettext = struct
 (* # 22 "src/oasis/OASISGettext.ml" *)
 
 
-  let ns_ str =
-    str
-
-
-  let s_ str =
-    str
-
-
-  let f_ (str: ('a, 'b, 'c, 'd) format4) =
-    str
+  let ns_ str = str
+  let s_ str = str
+  let f_ (str: ('a, 'b, 'c, 'd) format4) = str
 
 
   let fn_ fmt1 fmt2 n =
@@ -23,25 +16,338 @@ module OASISGettext = struct
       fmt2^^""
 
 
-  let init =
-    []
+  let init = []
+end
 
+module OASISString = struct
+(* # 22 "src/oasis/OASISString.ml" *)
 
-end
 
-module OASISExpr = struct
-(* # 22 "src/oasis/OASISExpr.ml" *)
+  (** Various string utilities.
 
+      Mostly inspired by extlib and batteries ExtString and BatString libraries.
 
+      @author Sylvain Le Gall
+  *)
 
 
+  let nsplitf str f =
+    if str = "" then
+      []
+    else
+      let buf = Buffer.create 13 in
+      let lst = ref [] in
+      let push () =
+        lst := Buffer.contents buf :: !lst;
+        Buffer.clear buf
+      in
+      let str_len = String.length str in
+      for i = 0 to str_len - 1 do
+        if f str.[i] then
+          push ()
+        else
+          Buffer.add_char buf str.[i]
+      done;
+      push ();
+      List.rev !lst
+
+
+  (** [nsplit c s] Split the string [s] at char [c]. It doesn't include the
+      separator.
+  *)
+  let nsplit str c =
+    nsplitf str ((=) c)
+
+
+  let find ~what ?(offset=0) str =
+    let what_idx = ref 0 in
+    let str_idx = ref offset in
+    while !str_idx < String.length str &&
+          !what_idx < String.length what do
+      if str.[!str_idx] = what.[!what_idx] then
+        incr what_idx
+      else
+        what_idx := 0;
+      incr str_idx
+    done;
+    if !what_idx <> String.length what then
+      raise Not_found
+    else
+      !str_idx - !what_idx
+
+
+  let sub_start str len =
+    let str_len = String.length str in
+    if len >= str_len then
+      ""
+    else
+      String.sub str len (str_len - len)
+
+
+  let sub_end ?(offset=0) str len =
+    let str_len = String.length str in
+    if len >= str_len then
+      ""
+    else
+      String.sub str 0 (str_len - len)
+
+
+  let starts_with ~what ?(offset=0) str =
+    let what_idx = ref 0 in
+    let str_idx = ref offset in
+    let ok = ref true in
+    while !ok &&
+          !str_idx < String.length str &&
+          !what_idx < String.length what do
+      if str.[!str_idx] = what.[!what_idx] then
+        incr what_idx
+      else
+        ok := false;
+      incr str_idx
+    done;
+    !what_idx = String.length what
+
+
+  let strip_starts_with ~what str =
+    if starts_with ~what str then
+      sub_start str (String.length what)
+    else
+      raise Not_found
+
+
+  let ends_with ~what ?(offset=0) str =
+    let what_idx = ref ((String.length what) - 1) in
+    let str_idx = ref ((String.length str) - 1) in
+    let ok = ref true in
+    while !ok &&
+          offset <= !str_idx &&
+          0 <= !what_idx do
+      if str.[!str_idx] = what.[!what_idx] then
+        decr what_idx
+      else
+        ok := false;
+      decr str_idx
+    done;
+    !what_idx = -1
+
+
+  let strip_ends_with ~what str =
+    if ends_with ~what str then
+      sub_end str (String.length what)
+    else
+      raise Not_found
+
+
+  let replace_chars f s =
+    let buf = Buffer.create (String.length s) in
+    String.iter (fun c -> Buffer.add_char buf (f c)) s;
+    Buffer.contents buf
+
+  let lowercase_ascii =
+    replace_chars
+      (fun c ->
+         if (c >= 'A' && c <= 'Z') then
+           Char.chr (Char.code c + 32)
+         else
+           c)
+
+  let uncapitalize_ascii s =
+    if s <> "" then
+      (lowercase_ascii (String.sub s 0 1)) ^ (String.sub s 1 ((String.length s) - 1))
+    else
+      s
+
+  let uppercase_ascii =
+    replace_chars
+      (fun c ->
+         if (c >= 'a' && c <= 'z') then
+           Char.chr (Char.code c - 32)
+         else
+           c)
+
+  let capitalize_ascii s =
+    if s <> "" then
+      (uppercase_ascii (String.sub s 0 1)) ^ (String.sub s 1 ((String.length s) - 1))
+    else
+      s
+
+end
+
+module OASISUtils = struct
+(* # 22 "src/oasis/OASISUtils.ml" *)
+
 
   open OASISGettext
 
 
-  type test = string
+  module MapExt =
+  struct
+    module type S =
+    sig
+      include Map.S
+      val add_list: 'a t -> (key * 'a) list -> 'a t
+      val of_list: (key * 'a) list -> 'a t
+      val to_list: 'a t -> (key * 'a) list
+    end
 
+    module Make (Ord: Map.OrderedType) =
+    struct
+      include Map.Make(Ord)
 
+      let rec add_list t =
+        function
+          | (k, v) :: tl -> add_list (add k v t) tl
+          | [] -> t
+
+      let of_list lst = add_list empty lst
+
+      let to_list t = fold (fun k v acc -> (k, v) :: acc) t []
+    end
+  end
+
+
+  module MapString = MapExt.Make(String)
+
+
+  module SetExt  =
+  struct
+    module type S =
+    sig
+      include Set.S
+      val add_list: t -> elt list -> t
+      val of_list: elt list -> t
+      val to_list: t -> elt list
+    end
+
+    module Make (Ord: Set.OrderedType) =
+    struct
+      include Set.Make(Ord)
+
+      let rec add_list t =
+        function
+          | e :: tl -> add_list (add e t) tl
+          | [] -> t
+
+      let of_list lst = add_list empty lst
+
+      let to_list = elements
+    end
+  end
+
+
+  module SetString = SetExt.Make(String)
+
+
+  let compare_csl s1 s2 =
+    String.compare (OASISString.lowercase_ascii s1) (OASISString.lowercase_ascii s2)
+
+
+  module HashStringCsl =
+    Hashtbl.Make
+      (struct
+         type t = string
+         let equal s1 s2 = (compare_csl s1 s2) = 0
+         let hash s = Hashtbl.hash (OASISString.lowercase_ascii s)
+       end)
+
+  module SetStringCsl =
+    SetExt.Make
+      (struct
+         type t = string
+         let compare = compare_csl
+       end)
+
+
+  let varname_of_string ?(hyphen='_') s =
+    if String.length s = 0 then
+      begin
+        invalid_arg "varname_of_string"
+      end
+    else
+      begin
+        let buf =
+          OASISString.replace_chars
+            (fun c ->
+               if ('a' <= c && c <= 'z')
+                 ||
+                  ('A' <= c && c <= 'Z')
+                 ||
+                  ('0' <= c && c <= '9') then
+                 c
+               else
+                 hyphen)
+            s;
+        in
+        let buf =
+          (* Start with a _ if digit *)
+          if '0' <= s.[0] && s.[0] <= '9' then
+            "_"^buf
+          else
+            buf
+        in
+          OASISString.lowercase_ascii buf
+      end
+
+
+  let varname_concat ?(hyphen='_') p s =
+    let what = String.make 1 hyphen in
+    let p =
+      try
+        OASISString.strip_ends_with ~what p
+      with Not_found ->
+        p
+    in
+    let s =
+      try
+        OASISString.strip_starts_with ~what s
+      with Not_found ->
+        s
+    in
+      p^what^s
+
+
+  let is_varname str =
+    str = varname_of_string str
+
+
+  let failwithf fmt = Printf.ksprintf failwith fmt
+
+
+  let rec file_location ?pos1 ?pos2 ?lexbuf () =
+      match pos1, pos2, lexbuf with
+      | Some p, None, _ | None, Some p, _ ->
+        file_location ~pos1:p ~pos2:p ?lexbuf ()
+      | Some p1, Some p2, _ ->
+        let open Lexing in
+        let fn, lineno = p1.pos_fname, p1.pos_lnum in
+        let c1 = p1.pos_cnum - p1.pos_bol in
+        let c2 = c1 + (p2.pos_cnum - p1.pos_cnum) in
+        Printf.sprintf (f_ "file %S, line %d, characters %d-%d")  fn lineno c1 c2
+      | _, _, Some lexbuf ->
+        file_location
+          ~pos1:(Lexing.lexeme_start_p lexbuf)
+          ~pos2:(Lexing.lexeme_end_p lexbuf)
+          ()
+      | None, None, None ->
+        s_ "<position undefined>"
+
+
+  let failwithpf ?pos1 ?pos2 ?lexbuf fmt =
+    let loc = file_location ?pos1 ?pos2 ?lexbuf () in
+    Printf.ksprintf (fun s -> failwith (Printf.sprintf "%s: %s" loc s)) fmt
+
+
+end
+
+module OASISExpr = struct
+(* # 22 "src/oasis/OASISExpr.ml" *)
+
+
+  open OASISGettext
+  open OASISUtils
+
+
+  type test = string
   type flag = string
 
 
@@ -54,7 +360,6 @@ module OASISExpr = struct
     | ETest of test * string
 
 
-
   type 'a choices = (t * 'a) list
 
 
@@ -129,7 +434,7 @@ module OASISExpr = struct
 end
 
 
-# 132 "myocamlbuild.ml"
+# 437 "myocamlbuild.ml"
 module BaseEnvLight = struct
 (* # 22 "src/base/BaseEnvLight.ml" *)
 
@@ -140,129 +445,103 @@ module BaseEnvLight = struct
   type t = string MapString.t
 
 
-  let default_filename =
-    Filename.concat
-      (Sys.getcwd ())
-      "setup.data"
+  let default_filename = Filename.concat (Sys.getcwd ()) "setup.data"
 
 
-  let load ?(allow_empty=false) ?(filename=default_filename) () =
-    if Sys.file_exists filename then
-      begin
-        let chn =
-          open_in_bin filename
-        in
-        let st =
-          Stream.of_channel chn
-        in
-        let line =
-          ref 1
-        in
-        let st_line =
-          Stream.from
-            (fun _ ->
-               try
-                 match Stream.next st with
-                   | '\n' -> incr line; Some '\n'
-                   | c -> Some c
-               with Stream.Failure -> None)
-        in
-        let lexer =
-          Genlex.make_lexer ["="] st_line
-        in
-        let rec read_file mp =
-          match Stream.npeek 3 lexer with
-            | [Genlex.Ident nm; Genlex.Kwd "="; Genlex.String value] ->
-                Stream.junk lexer;
-                Stream.junk lexer;
-                Stream.junk lexer;
-                read_file (MapString.add nm value mp)
-            | [] ->
-                mp
-            | _ ->
-                failwith
-                  (Printf.sprintf
-                     "Malformed data file '%s' line %d"
-                     filename !line)
-        in
-        let mp =
-          read_file MapString.empty
-        in
-          close_in chn;
-          mp
-      end
-    else if allow_empty then
-      begin
+  let load ?(allow_empty=false) ?(filename=default_filename) ?stream () =
+    let line = ref 1 in
+    let lexer st =
+      let st_line =
+        Stream.from
+          (fun _ ->
+             try
+               match Stream.next st with
+               | '\n' -> incr line; Some '\n'
+               | c -> Some c
+             with Stream.Failure -> None)
+      in
+      Genlex.make_lexer ["="] st_line
+    in
+    let rec read_file lxr mp =
+      match Stream.npeek 3 lxr with
+      | [Genlex.Ident nm; Genlex.Kwd "="; Genlex.String value] ->
+        Stream.junk lxr; Stream.junk lxr; Stream.junk lxr;
+        read_file lxr (MapString.add nm value mp)
+      | [] -> mp
+      | _ ->
+        failwith
+          (Printf.sprintf "Malformed data file '%s' line %d" filename !line)
+    in
+    match stream with
+    | Some st -> read_file (lexer st) MapString.empty
+    | None ->
+      if Sys.file_exists filename then begin
+        let chn = open_in_bin filename in
+        let st = Stream.of_channel chn in
+        try
+          let mp = read_file (lexer st) MapString.empty in
+          close_in chn; mp
+        with e ->
+          close_in chn; raise e
+      end else if allow_empty then begin
         MapString.empty
-      end
-    else
-      begin
+      end else begin
         failwith
           (Printf.sprintf
              "Unable to load environment, the file '%s' doesn't exist."
              filename)
       end
 
-
   let rec var_expand str env =
-    let buff =
-      Buffer.create ((String.length str) * 2)
-    in
-      Buffer.add_substitute
-        buff
-        (fun var ->
-           try
-             var_expand (MapString.find var env) env
-           with Not_found ->
-             failwith
-               (Printf.sprintf
-                  "No variable %s defined when trying to expand %S."
-                  var
-                  str))
-        str;
-      Buffer.contents buff
-
-
-  let var_get name env =
-    var_expand (MapString.find name env) env
-
-
-  let var_choose lst env =
-    OASISExpr.choose
-      (fun nm -> var_get nm env)
-      lst
+    let buff = Buffer.create ((String.length str) * 2) in
+    Buffer.add_substitute
+      buff
+      (fun var ->
+         try
+           var_expand (MapString.find var env) env
+         with Not_found ->
+           failwith
+             (Printf.sprintf
+                "No variable %s defined when trying to expand %S."
+                var
+                str))
+      str;
+    Buffer.contents buff
+
+
+  let var_get name env = var_expand (MapString.find name env) env
+  let var_choose lst env = OASISExpr.choose (fun nm -> var_get nm env) lst
 end
 
 
-# 237 "myocamlbuild.ml"
+# 517 "myocamlbuild.ml"
 module MyOCamlbuildFindlib = struct
 (* # 22 "src/plugins/ocamlbuild/MyOCamlbuildFindlib.ml" *)
 
 
   (** OCamlbuild extension, copied from
-    * http://brion.inria.fr/gallium/index.php/Using_ocamlfind_with_ocamlbuild
+    * https://ocaml.org/learn/tutorials/ocamlbuild/Using_ocamlfind_with_ocamlbuild.html
     * by N. Pouillard and others
     *
-    * Updated on 2009/02/28
+    * Updated on 2016-06-02
     *
     * Modified by Sylvain Le Gall
-    *)
+  *)
   open Ocamlbuild_plugin
 
 
-  (* these functions are not really officially exported *)
-  let run_and_read =
-    Ocamlbuild_pack.My_unix.run_and_read
+  type conf = {no_automatic_syntax: bool}
+
 
+  let run_and_read = Ocamlbuild_pack.My_unix.run_and_read
 
-  let blank_sep_strings =
-    Ocamlbuild_pack.Lexers.blank_sep_strings
+
+  let blank_sep_strings = Ocamlbuild_pack.Lexers.blank_sep_strings
 
 
   let exec_from_conf exec =
     let exec =
-      let env_filename = Pathname.basename BaseEnvLight.default_filename in
-      let env = BaseEnvLight.load ~filename:env_filename ~allow_empty:true () in
+      let env = BaseEnvLight.load ~allow_empty:true () in
       try
         BaseEnvLight.var_get exec env
       with Not_found ->
@@ -273,7 +552,7 @@ module MyOCamlbuildFindlib = struct
       if Sys.os_type = "Win32" then begin
         let buff = Buffer.create (String.length str) in
         (* Adapt for windowsi, ocamlbuild + win32 has a hard time to handle '\\'.
-         *)
+        *)
         String.iter
           (fun c -> Buffer.add_char buff (if c = '\\' then '/' else c))
           str;
@@ -282,7 +561,8 @@ module MyOCamlbuildFindlib = struct
         str
       end
     in
-      fix_win32 exec
+    fix_win32 exec
+
 
   let split s ch =
     let buf = Buffer.create 13 in
@@ -291,15 +571,15 @@ module MyOCamlbuildFindlib = struct
       x := (Buffer.contents buf) :: !x;
       Buffer.clear buf
     in
-      String.iter
-        (fun c ->
-           if c = ch then
-             flush ()
-           else
-             Buffer.add_char buf c)
-        s;
-      flush ();
-      List.rev !x
+    String.iter
+      (fun c ->
+         if c = ch then
+           flush ()
+         else
+           Buffer.add_char buf c)
+      s;
+    flush ();
+    List.rev !x
 
 
   let split_nl s = split s '\n'
@@ -315,7 +595,7 @@ module MyOCamlbuildFindlib = struct
 
   (* This lists all supported packages. *)
   let find_packages () =
-    List.map before_space (split_nl & run_and_read "ocamlfind list")
+    List.map before_space (split_nl & run_and_read (exec_from_conf "ocamlfind" ^ " list"))
 
 
   (* Mock to list available syntaxes. *)
@@ -338,80 +618,92 @@ module MyOCamlbuildFindlib = struct
   ]
 
 
-  let dispatch =
+  let dispatch conf =
     function
       | After_options ->
-          (* By using Before_options one let command line options have an higher
-           * priority on the contrary using After_options will guarantee to have
-           * the higher priority override default commands by ocamlfind ones *)
-          Options.ocamlc     := ocamlfind & A"ocamlc";
-          Options.ocamlopt   := ocamlfind & A"ocamlopt";
-          Options.ocamldep   := ocamlfind & A"ocamldep";
-          Options.ocamldoc   := ocamlfind & A"ocamldoc";
-          Options.ocamlmktop := ocamlfind & A"ocamlmktop";
-          Options.ocamlmklib := ocamlfind & A"ocamlmklib"
+        (* By using Before_options one let command line options have an higher
+         * priority on the contrary using After_options will guarantee to have
+         * the higher priority override default commands by ocamlfind ones *)
+        Options.ocamlc     := ocamlfind & A"ocamlc";
+        Options.ocamlopt   := ocamlfind & A"ocamlopt";
+        Options.ocamldep   := ocamlfind & A"ocamldep";
+        Options.ocamldoc   := ocamlfind & A"ocamldoc";
+        Options.ocamlmktop := ocamlfind & A"ocamlmktop";
+        Options.ocamlmklib := ocamlfind & A"ocamlmklib"
 
       | After_rules ->
 
-          (* When one link an OCaml library/binary/package, one should use
-           * -linkpkg *)
-          flag ["ocaml"; "link"; "program"] & A"-linkpkg";
-
-          (* For each ocamlfind package one inject the -package option when
-           * compiling, computing dependencies, generating documentation and
-           * linking. *)
-          List.iter
-            begin fun pkg ->
-              let base_args = [A"-package"; A pkg] in
-              (* TODO: consider how to really choose camlp4o or camlp4r. *)
-              let syn_args = [A"-syntax"; A "camlp4o"] in
-              let args =
+        (* Avoid warnings for unused tag *)
+        flag ["tests"] N;
+
+        (* When one link an OCaml library/binary/package, one should use
+         * -linkpkg *)
+        flag ["ocaml"; "link"; "program"] & A"-linkpkg";
+
+        (* For each ocamlfind package one inject the -package option when
+         * compiling, computing dependencies, generating documentation and
+         * linking. *)
+        List.iter
+          begin fun pkg ->
+            let base_args = [A"-package"; A pkg] in
+            (* TODO: consider how to really choose camlp4o or camlp4r. *)
+            let syn_args = [A"-syntax"; A "camlp4o"] in
+            let (args, pargs) =
               (* Heuristic to identify syntax extensions: whether they end in
                  ".syntax"; some might not.
-               *)
-                if Filename.check_suffix pkg "syntax" ||
-                   List.mem pkg well_known_syntax then
-                  syn_args @ base_args
-                else
-                  base_args
-              in
-              flag ["ocaml"; "compile";  "pkg_"^pkg] & S args;
-              flag ["ocaml"; "ocamldep"; "pkg_"^pkg] & S args;
-              flag ["ocaml"; "doc";      "pkg_"^pkg] & S args;
-              flag ["ocaml"; "link";     "pkg_"^pkg] & S base_args;
-              flag ["ocaml"; "infer_interface"; "pkg_"^pkg] & S args;
-            end
-            (find_packages ());
-
-          (* Like -package but for extensions syntax. Morover -syntax is useless
-           * when linking. *)
-          List.iter begin fun syntax ->
+              *)
+              if not (conf.no_automatic_syntax) &&
+                 (Filename.check_suffix pkg "syntax" ||
+                  List.mem pkg well_known_syntax) then
+                (syn_args @ base_args, syn_args)
+              else
+                (base_args, [])
+            in
+            flag ["ocaml"; "compile";  "pkg_"^pkg] & S args;
+            flag ["ocaml"; "ocamldep"; "pkg_"^pkg] & S args;
+            flag ["ocaml"; "doc";      "pkg_"^pkg] & S args;
+            flag ["ocaml"; "link";     "pkg_"^pkg] & S base_args;
+            flag ["ocaml"; "infer_interface"; "pkg_"^pkg] & S args;
+
+            (* TODO: Check if this is allowed for OCaml < 3.12.1 *)
+            flag ["ocaml"; "compile";  "package("^pkg^")"] & S pargs;
+            flag ["ocaml"; "ocamldep"; "package("^pkg^")"] & S pargs;
+            flag ["ocaml"; "doc";      "package("^pkg^")"] & S pargs;
+            flag ["ocaml"; "infer_interface"; "package("^pkg^")"] & S pargs;
+          end
+          (find_packages ());
+
+        (* Like -package but for extensions syntax. Morover -syntax is useless
+         * when linking. *)
+        List.iter begin fun syntax ->
           flag ["ocaml"; "compile";  "syntax_"^syntax] & S[A"-syntax"; A syntax];
           flag ["ocaml"; "ocamldep"; "syntax_"^syntax] & S[A"-syntax"; A syntax];
           flag ["ocaml"; "doc";      "syntax_"^syntax] & S[A"-syntax"; A syntax];
           flag ["ocaml"; "infer_interface"; "syntax_"^syntax] &
-                S[A"-syntax"; A syntax];
-          end (find_syntaxes ());
+          S[A"-syntax"; A syntax];
+        end (find_syntaxes ());
 
-          (* The default "thread" tag is not compatible with ocamlfind.
-           * Indeed, the default rules add the "threads.cma" or "threads.cmxa"
-           * options when using this tag. When using the "-linkpkg" option with
-           * ocamlfind, this module will then be added twice on the command line.
-           *
-           * To solve this, one approach is to add the "-thread" option when using
-           * the "threads" package using the previous plugin.
-           *)
-          flag ["ocaml"; "pkg_threads"; "compile"] (S[A "-thread"]);
-          flag ["ocaml"; "pkg_threads"; "doc"] (S[A "-I"; A "+threads"]);
-          flag ["ocaml"; "pkg_threads"; "link"] (S[A "-thread"]);
-          flag ["ocaml"; "pkg_threads"; "infer_interface"] (S[A "-thread"]);
-          flag ["ocaml"; "package(threads)"; "compile"] (S[A "-thread"]);
-          flag ["ocaml"; "package(threads)"; "doc"] (S[A "-I"; A "+threads"]);
-          flag ["ocaml"; "package(threads)"; "link"] (S[A "-thread"]);
-          flag ["ocaml"; "package(threads)"; "infer_interface"] (S[A "-thread"]);
+        (* The default "thread" tag is not compatible with ocamlfind.
+         * Indeed, the default rules add the "threads.cma" or "threads.cmxa"
+         * options when using this tag. When using the "-linkpkg" option with
+         * ocamlfind, this module will then be added twice on the command line.
+         *
+         * To solve this, one approach is to add the "-thread" option when using
+         * the "threads" package using the previous plugin.
+        *)
+        flag ["ocaml"; "pkg_threads"; "compile"] (S[A "-thread"]);
+        flag ["ocaml"; "pkg_threads"; "doc"] (S[A "-I"; A "+threads"]);
+        flag ["ocaml"; "pkg_threads"; "link"] (S[A "-thread"]);
+        flag ["ocaml"; "pkg_threads"; "infer_interface"] (S[A "-thread"]);
+        flag ["c"; "pkg_threads"; "compile"] (S[A "-thread"]);
+        flag ["ocaml"; "package(threads)"; "compile"] (S[A "-thread"]);
+        flag ["ocaml"; "package(threads)"; "doc"] (S[A "-I"; A "+threads"]);
+        flag ["ocaml"; "package(threads)"; "link"] (S[A "-thread"]);
+        flag ["ocaml"; "package(threads)"; "infer_interface"] (S[A "-thread"]);
+        flag ["c"; "package(threads)"; "compile"] (S[A "-thread"]);
 
       | _ ->
-          ()
+        ()
 end
 
 module MyOCamlbuildBase = struct
@@ -423,9 +715,6 @@ module MyOCamlbuildBase = struct
     *)
 
 
-
-
-
   open Ocamlbuild_plugin
   module OC = Ocamlbuild_pack.Ocaml_compiler
 
@@ -436,9 +725,6 @@ module MyOCamlbuildBase = struct
   type tag = string
 
 
-(* # 62 "src/plugins/ocamlbuild/MyOCamlbuildBase.ml" *)
-
-
   type t =
       {
         lib_ocaml: (name * dir list * string list) list;
@@ -451,9 +737,10 @@ module MyOCamlbuildBase = struct
       }
 
 
-  let env_filename =
-    Pathname.basename
-      BaseEnvLight.default_filename
+(* # 110 "src/plugins/ocamlbuild/MyOCamlbuildBase.ml" *)
+
+
+  let env_filename = Pathname.basename BaseEnvLight.default_filename
 
 
   let dispatch_combine lst =
@@ -472,12 +759,7 @@ module MyOCamlbuildBase = struct
 
 
   let dispatch t e =
-    let env =
-      BaseEnvLight.load
-        ~filename:env_filename
-        ~allow_empty:true
-        ()
-    in
+    let env = BaseEnvLight.load ~allow_empty:true () in
       match e with
         | Before_options ->
             let no_trailing_dot s =
@@ -505,7 +787,7 @@ module MyOCamlbuildBase = struct
                  | nm, [], intf_modules ->
                      ocaml_lib nm;
                      let cmis =
-                       List.map (fun m -> (String.uncapitalize m) ^ ".cmi")
+                       List.map (fun m -> (OASISString.uncapitalize_ascii m) ^ ".cmi")
                                 intf_modules in
                      dep ["ocaml"; "link"; "library"; "file:"^nm^".cma"] cmis
                  | nm, dir :: tl, intf_modules ->
@@ -518,7 +800,7 @@ module MyOCamlbuildBase = struct
                             ["compile"; "infer_interface"; "doc"])
                        tl;
                      let cmis =
-                       List.map (fun m -> dir^"/"^(String.uncapitalize m)^".cmi")
+                       List.map (fun m -> dir^"/"^(OASISString.uncapitalize_ascii m)^".cmi")
                                 intf_modules in
                      dep ["ocaml"; "link"; "library"; "file:"^dir^"/"^nm^".cma"]
                          cmis)
@@ -541,16 +823,18 @@ module MyOCamlbuildBase = struct
                    flag ["link"; "library"; "ocaml"; "native"; tag_libstubs lib]
                      (S[A"-cclib"; A("-l"^(nm_libstubs lib))]);
 
-                   flag ["link"; "program"; "ocaml"; "byte"; tag_libstubs lib]
-                     (S[A"-dllib"; A("dll"^(nm_libstubs lib))]);
+                   if bool_of_string (BaseEnvLight.var_get "native_dynlink" env) then
+                     flag ["link"; "program"; "ocaml"; "byte"; tag_libstubs lib]
+                         (S[A"-dllib"; A("dll"^(nm_libstubs lib))]);
 
                    (* When ocaml link something that use the C library, then one
                       need that file to be up to date.
+                      This holds both for programs and for libraries.
                     *)
-                   dep ["link"; "ocaml"; "program"; tag_libstubs lib]
+                   dep ["link"; "ocaml"; tag_libstubs lib]
                      [dir/"lib"^(nm_libstubs lib)^"."^(!Options.ext_lib)];
 
-                   dep  ["compile"; "ocaml"; "program"; tag_libstubs lib]
+                   dep  ["compile"; "ocaml"; tag_libstubs lib]
                      [dir/"lib"^(nm_libstubs lib)^"."^(!Options.ext_lib)];
 
                    (* TODO: be more specific about what depends on headers *)
@@ -580,25 +864,27 @@ module MyOCamlbuildBase = struct
             ()
 
 
-  let dispatch_default t =
+  let dispatch_default conf t =
     dispatch_combine
       [
         dispatch t;
-        MyOCamlbuildFindlib.dispatch;
+        MyOCamlbuildFindlib.dispatch conf;
       ]
 
 
 end
 
 
-# 594 "myocamlbuild.ml"
+# 878 "myocamlbuild.ml"
 open Ocamlbuild_plugin;;
 let package_default =
   {MyOCamlbuildBase.lib_ocaml = []; lib_c = []; flags = []; includes = []}
   ;;
 
-let dispatch_default = MyOCamlbuildBase.dispatch_default package_default;;
+let conf = {MyOCamlbuildFindlib.no_automatic_syntax = false}
+
+let dispatch_default = MyOCamlbuildBase.dispatch_default conf package_default;;
 
-# 603 "myocamlbuild.ml"
+# 889 "myocamlbuild.ml"
 (* OASIS_STOP *)
 Ocamlbuild_plugin.dispatch dispatch_default;;
