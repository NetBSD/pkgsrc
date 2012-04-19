$NetBSD: patch-configure.sh,v 1.1 2012/04/19 21:05:46 joerg Exp $

--- discount-2.1.2/configure.sh.orig	2012-04-19 14:00:16.000000000 +0000
+++ discount-2.1.2/configure.sh
@@ -76,11 +76,11 @@ AC_C_INLINE
 AC_SCALAR_TYPES sub hdr
 AC_CHECK_BASENAME
 
-AC_CHECK_HEADERS sys/types.h pwd.h && AC_CHECK_FUNCS getpwuid
+AC_CHECK_HEADERS sys/types.h pwd.h && AC_CHECK_FUNCS 'getpwuid(0)'
 
-if AC_CHECK_FUNCS srandom; then
+if AC_CHECK_FUNCS 'srandom(0)'; then
     AC_DEFINE 'INITRNG(x)' 'srandom((unsigned int)x)'
-elif AC_CHECK_FUNCS srand; then
+elif AC_CHECK_FUNCS 'srand(0)'; then
     AC_DEFINE 'INITRNG(x)' 'srand((unsigned int)x)'
 else
     AC_DEFINE 'INITRNG(x)' '(void)1'
@@ -102,7 +102,7 @@ else
     AC_DEFINE 'COINTOSS()' '1'
 fi
 
-if AC_CHECK_FUNCS strcasecmp; then
+if AC_CHECK_FUNCS 'strcasecmp("X", "x")'; then
     :
 elif AC_CHECK_FUNCS stricmp; then
     AC_DEFINE strcasecmp stricmp
@@ -110,7 +110,7 @@ else
     AC_FAIL "$TARGET requires either strcasecmp() or stricmp()"
 fi
 
-if AC_CHECK_FUNCS strncasecmp; then
+if AC_CHECK_FUNCS 'strncasecmp("X", "x", 1)'; then
     :
 elif AC_CHECK_FUNCS strnicmp; then
     AC_DEFINE strncasecmp strnicmp
@@ -118,7 +118,7 @@ else
     AC_FAIL "$TARGET requires either strncasecmp() or strnicmp()"
 fi
 
-if AC_CHECK_FUNCS fchdir || AC_CHECK_FUNCS getcwd ; then
+if AC_CHECK_FUNCS 'fchdir(0)' || AC_CHECK_FUNCS 'getcwd((char *)0, 0)'; then
     AC_SUB 'THEME' ''
 else
     AC_SUB 'THEME' '#'
