$NetBSD: patch-Wnn_romkan_rk__fundecl.h,v 1.1 2026/07/10 23:32:38 tsutsui Exp $

- Use proper function prototypes for -std=gnu23

--- Wnn/romkan/rk_fundecl.h.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/romkan/rk_fundecl.h
@@ -46,9 +46,9 @@ extern letter *ltrncpy FRWNN_PARAMS((let
 extern int ltrcmp FRWNN_PARAMS((letter*,letter*)),
   ltrncmp FRWNN_PARAMS((letter*,letter*,int));
 
-extern int romkan_init FRWNN_PARAMS((char*,letter,char,letter(*keyinfn)(),int(*bytcntfn)())),
-  romkan_init2 FRWNN_PARAMS((char*,letter,char,letter(*keyinfn)(),int(*bytcntfn)(),char,char,char)),
-  romkan_init3 FRWNN_PARAMS((char*,letter,letter,letter,letter(*keyinfn)(),int(*bytcntfn)(),int(*kbytcntfn)(),char,int));
+extern int romkan_init FRWNN_PARAMS((char*,letter,char,letter(*keyinfn) (void),int(*bytcntfn) (uns_chr *))),
+  romkan_init2 FRWNN_PARAMS((char*,letter,char,letter(*keyinfn) (void),int(*bytcntfn) (uns_chr *),char,char,char)),
+  romkan_init3 FRWNN_PARAMS((char*,letter,letter,letter,letter(*keyinfn) (void),int(*bytcntfn) (uns_chr *),int(*kbytcntfn) (uns_chr *),char,int));
 extern letter romkan_getc FRWNN_PARAMS((void)),
   *romkan_henkan FRWNN_PARAMS((letter)),
   romkan_next FRWNN_PARAMS((void));
