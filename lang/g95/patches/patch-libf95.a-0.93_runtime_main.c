$NetBSD: patch-libf95.a-0.93_runtime_main.c,v 1.1 2013/07/28 12:54:52 obache Exp $

* fixes missing restore stack address.  PR pkg/47906

--- libf95.a-0.93/runtime/main.c.orig	2010-04-18 15:47:28.000000000 +0000
+++ libf95.a-0.93/runtime/main.c
@@ -50,9 +50,11 @@ int main(int argc, char *argv[]) {
  * unaligned. */
 
 #if HAVE_REAL_10 == 1 || HAVE_REAL_10 == 2
+    int diff;
     asm("mov %%esp, %%eax\n"
 	"and $0x04, %%eax\n"
-	"sub %%eax, %%esp\n" : : : "%eax");
+	"movl %%eax, %0\n"
+	"sub %%eax, %%esp\n" : "=r"(diff) : : "%eax");
 #endif
 
     g95_runtime_start(argc, argv);
@@ -62,5 +64,10 @@ int main(int argc, char *argv[]) {
     memory_done();
     g95_runtime_stop();
 
+#if HAVE_REAL_10 == 1 || HAVE_REAL_10 == 2
+    asm("mov %0, %%eax\n"
+	"add %%eax, %%esp\n" : : "r"(diff) : "%eax");
+#endif
+
     return 0;
 }
