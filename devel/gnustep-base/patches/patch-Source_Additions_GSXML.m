$NetBSD: patch-Source_Additions_GSXML.m,v 1.1 2024/05/12 00:22:02 manu Exp $

Fix GSXML compatibility with libxml2 v2.11.0

From upstream
https://github.com/gnustep/libs-base/pull/295/files/9bd745c6b69159cd25150f8297e8aa6c33e2a69f

--- Source/Additions/GSXML.m.orig	2024-05-11 22:55:36.594575380 +0200
+++ Source/Additions/GSXML.m	2024-05-11 22:55:57.348514948 +0200
@@ -2670,12 +2670,14 @@
                   ctxt->validate = 0;
                   return NULL;
                 }
               ret->owner = 1;
+#if LIBXML_VERSION < 21100
               if (ret->checked == 0)
                 {
                   ret->checked = 1;
                 }
+#endif
             }
         }
     }
   return ret;
