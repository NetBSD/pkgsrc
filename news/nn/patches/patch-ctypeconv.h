$NetBSD: patch-ctypeconv.h,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- ctypeconv.h.orig	2026-05-17 09:34:59.950696268 +0000
+++ ctypeconv.h
@@ -0,0 +1,27 @@
+/* use macros to make the ctype conversion less clunky */
+
+#include <ctype.h>
+
+#ifdef isascii
+#ifndef HAVE_8BIT_CTYPE
+#define ISASCII(p)	isascii((unsigned char)(p))
+#else
+#define ISASCII(p)	1
+#endif
+#endif
+#define ISALPHA(p)	isalpha((unsigned char)(p))
+#define ISUPPER(p)	isupper((unsigned char)(p))
+#define ISLOWER(p)	islower((unsigned char)(p))
+#define ISDIGIT(p)	isdigit((unsigned char)(p))
+#define ISALNUM(p)	isalnum((unsigned char)(p))
+#define ISSPACE(p)	isspace((unsigned char)(p))
+#define ISPRINT(p)	isprint((unsigned char)(p))
+#define TOLOWER(p)	tolower((unsigned char)(p))
+#define TOUPPER(p)	toupper((unsigned char)(p))
+#ifdef _tolower
+#define _TOLOWER(p)	_tolower((unsigned char)(p))
+#endif
+#ifdef _toupper
+#define _TOUPPER(p)	_toupper((unsigned char)(p))
+#endif
+
