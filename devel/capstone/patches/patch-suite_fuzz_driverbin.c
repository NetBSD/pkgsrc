$NetBSD: patch-suite_fuzz_driverbin.c,v 1.2 2024/02/07 09:46:36 adam Exp $

no d_type / DT_REG on SunOS, skip check.

--- suite/fuzz/driverbin.c.orig	2023-08-22 16:03:55.000000000 +0000
+++ suite/fuzz/driverbin.c
@@ -35,9 +35,11 @@ int main(int argc, char** argv)
 
     while((dir = readdir(d)) != NULL) {
         //opens the file, get its size, and reads it into a buffer
+#ifdef DT_REG
         if (dir->d_type != DT_REG) {
             continue;
         }
+#endif
         printf("Running file %s ", dir->d_name);
         fflush(stdout);
         fp = fopen(dir->d_name, "rb");
