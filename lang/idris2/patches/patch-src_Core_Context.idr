$NetBSD: patch-src_Core_Context.idr,v 1.1 2023/11/06 17:17:51 pho Exp $

Add DESTDIR support.

TODO: Upstream this

--- src/Core/Context.idr.orig	2022-10-27 15:43:33.000000000 +0000
+++ src/Core/Context.idr
@@ -2112,6 +2112,10 @@ setOutputDir : {auto c : Ref Ctxt Defs} 
 setOutputDir dir = update Ctxt { options->dirs->output_dir := dir }
 
 export
+setStageDir : {auto c : Ref Ctxt Defs} -> Maybe String -> Core ()
+setStageDir dir = update Ctxt { options->dirs->stage_dir := dir }
+
+export
 setSourceDir : {auto c : Ref Ctxt Defs} -> Maybe String -> Core ()
 setSourceDir mdir = update Ctxt { options->dirs->source_dir := mdir }
 
