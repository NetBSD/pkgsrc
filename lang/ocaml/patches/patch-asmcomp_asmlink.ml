$NetBSD: patch-asmcomp_asmlink.ml,v 1.1 2015/01/20 14:12:25 jaapb Exp $

pkgsrc_runtime flag
--- asmcomp/asmlink.ml.orig	2014-05-21 15:08:11.000000000 +0000
+++ asmcomp/asmlink.ml
@@ -98,6 +98,13 @@ let add_ccobjs l =
   end
 
 let runtime_lib () =
+	if !Clflags.pkgsrc_runtime
+	then begin
+		if !Clflags.gprofile
+		then [ "-lasmrunp" ]
+		else [ "-lasmrun" ^ !Clflags.runtime_variant ]
+	end
+	else
   let libname =
     if !Clflags.gprofile
     then "libasmrunp" ^ ext_lib
