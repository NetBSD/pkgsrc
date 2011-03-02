$NetBSD: patch-main.cc,v 1.1 2011/03/02 15:43:12 ryoon Exp $

--- main.cc.orig	2010-11-21 12:02:12.000000000 +0000
+++ main.cc
@@ -622,7 +622,7 @@ int bx_init_main(int argc, char *argv[])
     }
     arg++;
   }
-#if BX_WITH_CARBON
+#if BROKEN_BX_WITH_CARBON
   if(!getenv("BXSHARE"))
   {
     CFBundleRef mainBundle;
