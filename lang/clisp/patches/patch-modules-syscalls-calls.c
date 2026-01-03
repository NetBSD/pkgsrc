$NetBSD: patch-modules-syscalls-calls.c,v 1.1 2026/01/03 03:26:07 dholland Exp $

Hack around some kind of weird configury problem where the autoconf
muck is apparently setting the macros for strverscmp one way but
substituting something else into the replacement <string.h> so it
disappears.

Fixes build with gcc14.

--- modules/syscalls/calls.c~	2010-06-18 20:05:54.000000000 +0000
+++ modules/syscalls/calls.c
@@ -89,6 +89,14 @@ DEFINE_GUID(FMTID_UserDefinedProperties,
 #include <stdlib.h>
 #include <string.h>             /* for strcpy(), strcat() */
 
+/*
+ * This lives in src/gllib/string.h, which is supposed to be hiding
+ * the real string.h, except there's something wrong with the
+ * configury such that it gets disabled there. Since that's now fatal
+ * with gcc14, kludge around the problem.
+ */
+int strverscmp(const char *, const char *);
+
 /* #define DEBUG */
 #if defined(DEBUG)
 extern object nobject_out (FILE* stream, object obj);
