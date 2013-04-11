$NetBSD: patch-xen_arch_x86_string.c,v 1.1 2013/04/11 19:57:51 joerg Exp $

--- xen/arch/x86/string.c.orig	2013-03-25 12:54:07.000000000 +0000
+++ xen/arch/x86/string.c
@@ -8,6 +8,21 @@
 #include <xen/config.h>
 #include <xen/lib.h>
 
+#undef memcmp
+int
+memcmp(const void *s1, const void *s2, size_t n)
+{
+	const unsigned char *p1 = s1;
+	const unsigned char *p2 = s2;
+	while (n-- != 0) {
+		if (*p1 != *p2)
+			return *p1 - *p2;
+		++p1;
+		++p2;
+	}
+	return 0;
+}
+
 #undef memcpy
 void *memcpy(void *dest, const void *src, size_t n)
 {
