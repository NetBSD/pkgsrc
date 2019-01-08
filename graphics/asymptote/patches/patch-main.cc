$NetBSD: patch-main.cc,v 1.1 2019/01/08 10:58:09 markd Exp $

Port to gc-7.6.8
(commit 38a59370dc5ac720c29e1424614a10f7384b943f)

--- main.cc.orig	2017-03-22 07:56:46.000000000 +0000
+++ main.cc
@@ -214,3 +214,9 @@ int main(int argc, char *argv[]) 
 #endif  
   asymain(&args);
 }
+
+#ifdef USEGC
+GC_API void GC_CALL GC_throw_bad_alloc() {
+  std::bad_alloc();
+}
+#endif
