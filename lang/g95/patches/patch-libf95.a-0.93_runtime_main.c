$NetBSD: patch-libf95.a-0.93_runtime_main.c,v 1.3 2014/02/17 16:49:14 jperkin Exp $

* fixes missing restore stack address.  PR pkg/47906
* Make MAIN_ weak to allow linking libf95 dynamically.

--- libf95.a-0.93/runtime/main.c.orig	2010-04-18 15:47:28.000000000 +0000
+++ libf95.a-0.93/runtime/main.c
@@ -37,11 +37,14 @@
 void __main(void) {}
 #endif
 
-
-
-
 /* main()-- Entry point for the fortran program */
-void MAIN_(void);
+#ifdef __APPLE__
+void MAIN_(void);
+#elif __GNUC__ - 0 == 4 && __GNUC_MINOR__ < 2
+extern void weak_MAIN_(void) __attribute__((__weakref__("MAIN_")));
+#else
+static void weak_MAIN_(void) __attribute__((__weakref__("MAIN_")));
+#endif
 
 int main(int argc, char *argv[]) {
 
@@ -50,17 +53,30 @@ int main(int argc, char *argv[]) {
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
 
-    MAIN_();      /* Call the Fortran main program. */
+#ifdef __APPLE__
+    if (MAIN_)
+        MAIN_();      /* Call the Fortran main program. */
+#else
+    if (weak_MAIN_)
+        weak_MAIN_();      /* Call the Fortran main program. */
+#endif
 
     memory_done();
     g95_runtime_stop();
 
+#if HAVE_REAL_10 == 1 || HAVE_REAL_10 == 2
+    asm("mov %0, %%eax\n"
+	"add %%eax, %%esp\n" : : "r"(diff) : "%eax");
+#endif
+
     return 0;
 }
