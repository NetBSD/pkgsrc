$NetBSD: patch-config_endian.c,v 1.1 2025/07/02 03:12:02 markd Exp $

main() returns int

--- config/endian.c.orig	2008-03-31 11:43:59.000000000 +0000
+++ config/endian.c
@@ -1,5 +1,5 @@
 #include <stdio.h>
-main()
+int main()
 {
   if (sizeof(long) == 4)
   {
