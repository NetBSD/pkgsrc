$NetBSD: patch-register.c,v 1.1 2015/04/12 16:09:27 tnn Exp $

Add patch from Debian (security_format.patch) to fix unsafe format string usage.

--- register.c.orig	2004-04-21 07:04:10.000000000 +0000
+++ register.c
@@ -205,7 +205,7 @@ int main(int argc, char **argv)
  char reg_source[200];
  int i;
 
- printf(M_REGISTER_BANNER);
+ fputs(M_REGISTER_BANNER, stdout);
  integrity_pattern[0]--;
  build_crc32_table();
  if(argc!=2)
