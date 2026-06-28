$NetBSD: patch-Xwnmo_romkan__m_rk__multi.h,v 1.1 2026/06/28 06:16:28 tsutsui Exp $

- Appease -Wchar-subscripts warnings/errors

--- Xwnmo/romkan_m/rk_multi.h.orig	2026-06-23 18:36:03.780858234 +0000
+++ Xwnmo/romkan_m/rk_multi.h
@@ -272,7 +272,7 @@ typedef struct _Romkan
   int lastoutlen, lastkbflen;
   int hyonum;
 
-  char ebf_sw;
+  int ebf_sw;
   letter oneletter[2];
 
   modeswtable rk_modesw;
