$NetBSD: patch-src_solver_opamCudf.ml,v 1.1 2016/06/19 23:23:02 jaapb Exp $

Reflect API change in dose3
--- src/solver/opamCudf.ml.orig	2015-04-27 07:46:51.000000000 +0000
+++ src/solver/opamCudf.ml
@@ -611,7 +611,7 @@ let check_cudf_version =
           `Compat
         | s::_ ->
           match OpamMisc.split s ' ' with
-          | "aspcud"::_::v::_ when Debian.Version.compare v "1.9" >= 0 ->
+          | "aspcud"::_::v::_ when Versioning.Debian.compare v "1.9" >= 0 ->
             log "Solver is aspcud > 1.9: using latest version criteria";
             `Latest
           | _ ->
