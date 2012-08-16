$NetBSD: patch-Src_zsh__system.h,v 1.1 2012/08/16 13:31:21 wiz Exp $

Fix build on NetBSD-5.99.40.
Patch from Peter Stephenson <Peter.Stephenson@csr.com> on zsh-workers.

--- Src/zsh_system.h.orig	2012-06-21 18:36:09.000000000 +0000
+++ Src/zsh_system.h
@@ -874,7 +874,3 @@ extern short ospeed;
 #  endif
 # endif
 #endif
-
-#ifdef TGOTO_PROTO_MISSING
-char *tgoto(const char *cap, int col, int row);
-#endif
