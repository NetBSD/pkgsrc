$NetBSD: patch-myctype.h,v 1.1 2026/04/14 14:26:36 christos Exp $

Provide a replacement ctype.h that avoids using the array macros
and makes the argument be in the allowed range

--- /dev/null	2026-04-14 10:13:22.713894271 -0400
+++ myctype.h	2026-04-14 10:13:05.352205521 -0400
@@ -0,0 +1,44 @@
+
+/*
+ * Replace boobytrapped versions with safe ones
+ */
+#include <ctype.h>
+
+#undef	isalnum
+#undef	isalpha
+#undef	iscntrl
+#undef	isdigit
+#undef	isgraph
+#undef	islower
+#undef	isprint
+#undef	ispunct
+#undef	isspace
+#undef	isupper
+#undef	isxdigit
+#undef	tolower
+#undef	toupper
+#undef	isascii
+#undef	toascii
+#undef _tolower
+#undef _toupper
+#undef	isblank
+
+
+#define	isalnum(c)	(isalnum)((unsigned char)(c))
+#define	isalpha(c)	(isalpha)((unsigned char)(c))
+#define	iscntrl(c)	(iscntrl)((unsigned char)(c))
+#define	isdigit(c)	(isdigit)((unsigned char)(c))
+#define	isgraph(c)	(isgraph)((unsigned char)(c))
+#define	islower(c)	(islower)((unsigned char)(c))
+#define	isprint(c)	(isprint)((unsigned char)(c))
+#define	ispunct(c)	(ispunct)((unsigned char)(c))
+#define	isspace(c)	(isspace)((unsigned char)(c))
+#define	isupper(c)	(isupper)((unsigned char)(c))
+#define	isxdigit(c)	(isxdigit)((unsigned char)(c))
+#define	tolower(c)	(tolower)((unsigned char)(c))
+#define	toupper(c)	(toupper)((unsigned char)(c))
+#define	isascii(c)	(isascii)((unsigned char)(c))
+#define	toascii(c)	(toascii)((unsigned char)(c))
+#define _tolower(c)	(_tolower)((unsigned char)(c))
+#define _toupper(c)	(_toupper)((unsigned char)(c))
+#define	isblank(c)	(isblank)((unsigned char)(c))
