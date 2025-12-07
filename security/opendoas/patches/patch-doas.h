$NetBSD: patch-doas.h,v 1.1 2025/12/07 12:21:56 vins Exp $

Change permit to be more bits away from deny.

--- doas.h.orig	2025-12-07 12:02:39.178742668 +0000
+++ doas.h
@@ -36,7 +36,7 @@ struct passwd;
 char **prepenv(const struct rule *, const struct passwd *,
     const struct passwd *);
 
-#define PERMIT	1
+#define PERMIT	-1
 #define DENY	2
 
 #define NOPASS		0x1
