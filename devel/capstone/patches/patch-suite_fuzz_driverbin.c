$NetBSD: patch-suite_fuzz_driverbin.c,v 1.1 2022/03/26 19:25:51 tnn Exp $

no d_type / DT_REG on SunOS, skip check.

--- suite/fuzz/driverbin.c.orig	2020-05-08 10:03:30.000000000 +0000
+++ suite/fuzz/driverbin.c
@@ -34,9 +34,11 @@ int main(int argc, char** argv)
 
     while((dir = readdir(d)) != NULL) {
         //opens the file, get its size, and reads it into a buffer
+#ifdef DT_REG
         if (dir->d_type != DT_REG) {
             continue;
         }
+#endif
 
         printf("Running %s\n", dir->d_name);
         fflush(stdout);
