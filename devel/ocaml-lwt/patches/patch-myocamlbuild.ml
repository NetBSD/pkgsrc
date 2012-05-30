$NetBSD: patch-myocamlbuild.ml,v 1.1 2012/05/30 13:40:59 wiz Exp $

Patch the OASIS build system to work with NetBSD paths 
--- myocamlbuild.ml.orig	2011-12-12 12:52:35.000000000 +0000
+++ myocamlbuild.ml
@@ -31,9 +31,9 @@ let search_paths = [
 ]
 
 (* OASIS_START *)
-(* DO NOT EDIT (digest: 4c177063a31680580ca13639e7a11972) *)
+(* DO NOT EDIT (digest: 9b0df115f3f16175de7168e762f22e08) *)
 module OASISGettext = struct
-# 21 "/home/chambart/bordel/oasis/oasis/src/oasis/OASISGettext.ml"
+# 21 "/home/jaapb/progs/ocsigen-repos/oasis/src/oasis/OASISGettext.ml"
   
   let ns_ str = 
     str
@@ -56,7 +56,7 @@ module OASISGettext = struct
 end
 
 module OASISExpr = struct
-# 21 "/home/chambart/bordel/oasis/oasis/src/oasis/OASISExpr.ml"
+# 21 "/home/jaapb/progs/ocsigen-repos/oasis/src/oasis/OASISExpr.ml"
   
   
   
@@ -147,7 +147,7 @@ end
 
 
 module BaseEnvLight = struct
-# 21 "/home/chambart/bordel/oasis/oasis/src/base/BaseEnvLight.ml"
+# 21 "/home/jaapb/progs/ocsigen-repos/oasis/src/base/BaseEnvLight.ml"
   
   module MapString = Map.Make(String)
   
@@ -244,7 +244,7 @@ end
 
 
 module MyOCamlbuildFindlib = struct
-# 21 "/home/chambart/bordel/oasis/oasis/src/plugins/ocamlbuild/MyOCamlbuildFindlib.ml"
+# 21 "/home/jaapb/progs/ocsigen-repos/oasis/src/plugins/ocamlbuild/MyOCamlbuildFindlib.ml"
   
   (** OCamlbuild extension, copied from 
     * http://brion.inria.fr/gallium/index.php/Using_ocamlfind_with_ocamlbuild
@@ -352,7 +352,7 @@ module MyOCamlbuildFindlib = struct
 end
 
 module MyOCamlbuildBase = struct
-# 21 "/home/chambart/bordel/oasis/oasis/src/plugins/ocamlbuild/MyOCamlbuildBase.ml"
+# 21 "/home/jaapb/progs/ocsigen-repos/oasis/src/plugins/ocamlbuild/MyOCamlbuildBase.ml"
   
   (** Base functions for writing myocamlbuild.ml
       @author Sylvain Le Gall
@@ -367,7 +367,7 @@ module MyOCamlbuildBase = struct
   type name = string 
   type tag = string 
   
-# 55 "/home/chambart/bordel/oasis/oasis/src/plugins/ocamlbuild/MyOCamlbuildBase.ml"
+# 55 "/home/jaapb/progs/ocsigen-repos/oasis/src/plugins/ocamlbuild/MyOCamlbuildBase.ml"
   
   type t =
       {
@@ -491,15 +491,15 @@ let package_default =
           ("tests/test", ["tests"]);
           ("src/text/lwt-text", ["src/text"]);
           ("syntax/lwt-syntax", ["syntax"]);
-          ("src/top/lwt-top", ["src/top"]);
           ("src/preemptive/lwt-preemptive", ["src/preemptive"]);
-          ("src/simple_top/lwt-simple-top", ["src/simple_top"]);
-          ("src/glib/lwt-glib", ["src/glib"]);
+          ("src/top/lwt-top", ["src/top"]);
           ("syntax/lwt-syntax-log", ["syntax"]);
           ("src/extra/lwt-extra", ["src/extra"]);
           ("syntax/optcomp", ["syntax"]);
           ("syntax/lwt-syntax-options", ["syntax"]);
-          ("src/ssl/lwt-ssl", ["src/ssl"])
+          ("src/ssl/lwt-ssl", ["src/ssl"]);
+          ("src/simple_top/lwt-simple-top", ["src/simple_top"]);
+          ("src/glib/lwt-glib", ["src/glib"])
        ];
      lib_c =
        [
@@ -514,19 +514,48 @@ let package_default =
           (["oasis_library_lwt_unix_cclib"; "link"],
             [
                (OASISExpr.EBool true, S []);
-               (OASISExpr.EFlag "libev", S [A "-cclib"; A "-lev"]);
+               (OASISExpr.EFlag "libev",
+                 S
+                   [
+                      A "-cclib";
+                      A "-lev";
+                      A "-cclib";
+                      A "-L${LOCALBASE}/lib/ev";
+                      A "-cclib";
+                      A "-Wl,-R${LOCALBASE}/lib/ev"
+                   ]);
                (OASISExpr.ENot (OASISExpr.ETest ("os_type", "Win32")),
                  S [A "-cclib"; A "-lpthread"]);
                (OASISExpr.EAnd
                   (OASISExpr.ENot (OASISExpr.ETest ("os_type", "Win32")),
                     OASISExpr.EFlag "libev"),
-                 S [A "-cclib"; A "-lpthread"; A "-cclib"; A "-lev"]);
+                 S
+                   [
+                      A "-cclib";
+                      A "-lpthread";
+                      A "-cclib";
+                      A "-lev";
+                      A "-cclib";
+                      A "-L${LOCALBASE}/lib/ev";
+                      A "-cclib";
+                      A "-Wl,-R${LOCALBASE}/lib/ev"
+                   ]);
                (OASISExpr.ETest ("os_type", "Win32"),
                  S [A "-cclib"; A "ws2_32.lib"]);
                (OASISExpr.EAnd
                   (OASISExpr.ETest ("os_type", "Win32"),
                     OASISExpr.EFlag "libev"),
-                 S [A "-cclib"; A "ws2_32.lib"; A "-cclib"; A "-lev"]);
+                 S
+                   [
+                      A "-cclib";
+                      A "ws2_32.lib";
+                      A "-cclib";
+                      A "-lev";
+                      A "-cclib";
+                      A "-L${LOCALBASE}/lib/ev";
+                      A "-cclib";
+                      A "-Wl,-R${LOCALBASE}/lib/ev"
+                   ]);
                (OASISExpr.EAnd
                   (OASISExpr.ETest ("os_type", "Win32"),
                     OASISExpr.ENot (OASISExpr.ETest ("os_type", "Win32"))),
@@ -543,24 +572,46 @@ let package_default =
                       A "-cclib";
                       A "-lpthread";
                       A "-cclib";
-                      A "-lev"
+                      A "-lev";
+                      A "-cclib";
+                      A "-L${LOCALBASE}/lib/ev";
+                      A "-cclib";
+                      A "-Wl,-R${LOCALBASE}/lib/ev"
                    ])
             ]);
           (["oasis_library_lwt_unix_cclib"; "ocamlmklib"; "c"],
             [
                (OASISExpr.EBool true, S []);
-               (OASISExpr.EFlag "libev", S [A "-lev"]);
+               (OASISExpr.EFlag "libev",
+                 S
+                   [
+                      A "-lev";
+                      A "-L${LOCALBASE}/lib/ev";
+                      A "-Wl,-R${LOCALBASE}/lib/ev"
+                   ]);
                (OASISExpr.ENot (OASISExpr.ETest ("os_type", "Win32")),
                  S [A "-lpthread"]);
                (OASISExpr.EAnd
                   (OASISExpr.ENot (OASISExpr.ETest ("os_type", "Win32")),
                     OASISExpr.EFlag "libev"),
-                 S [A "-lpthread"; A "-lev"]);
+                 S
+                   [
+                      A "-lpthread";
+                      A "-lev";
+                      A "-L${LOCALBASE}/lib/ev";
+                      A "-Wl,-R${LOCALBASE}/lib/ev"
+                   ]);
                (OASISExpr.ETest ("os_type", "Win32"), S [A "ws2_32.lib"]);
                (OASISExpr.EAnd
                   (OASISExpr.ETest ("os_type", "Win32"),
                     OASISExpr.EFlag "libev"),
-                 S [A "ws2_32.lib"; A "-lev"]);
+                 S
+                   [
+                      A "ws2_32.lib";
+                      A "-lev";
+                      A "-L${LOCALBASE}/lib/ev";
+                      A "-Wl,-R${LOCALBASE}/lib/ev"
+                   ]);
                (OASISExpr.EAnd
                   (OASISExpr.ETest ("os_type", "Win32"),
                     OASISExpr.ENot (OASISExpr.ETest ("os_type", "Win32"))),
@@ -570,7 +621,14 @@ let package_default =
                      (OASISExpr.ETest ("os_type", "Win32"),
                        OASISExpr.ENot (OASISExpr.ETest ("os_type", "Win32"))),
                     OASISExpr.EFlag "libev"),
-                 S [A "ws2_32.lib"; A "-lpthread"; A "-lev"])
+                 S
+                   [
+                      A "ws2_32.lib";
+                      A "-lpthread";
+                      A "-lev";
+                      A "-L${LOCALBASE}/lib/ev";
+                      A "-Wl,-R${LOCALBASE}/lib/ev"
+                   ])
             ])
        ];
      }
