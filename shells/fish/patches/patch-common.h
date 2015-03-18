$NetBSD: patch-common.h,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- common.h.orig	2015-03-17 21:55:55.000000000 +0000
+++ common.h
@@ -654,7 +654,7 @@ wcstring wsetlocale(int category, const 
    \return zero if needle is not found, of if needle is null, non-zero otherwise
 */
 __sentinel bool contains_internal(const wchar_t *needle, ...);
-__sentinel bool contains_internal(const wcstring &needle, ...);
+__sentinel bool contains_internal(const wcstring *needle, ...);
 
 /**
    Call read while blocking the SIGCHLD signal. Should only be called
