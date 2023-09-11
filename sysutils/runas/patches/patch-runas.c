$NetBSD: patch-runas.c,v 1.1 2023/09/11 14:01:39 bacon Exp $

# Linux missing strl*()

--- runas.c.orig	2021-02-04 13:39:53.796790582 +0000
+++ runas.c
@@ -18,6 +18,11 @@
 #include <unistd.h>
 #include <limits.h>
 
+#ifdef __linux__
+#define ARG_MAX	2097152	// getconf ARG_MAX CentOS 7
+#endif
+
+// Remove usage() from libbacon?
 void    usage(char *argv[])
 
 {
@@ -25,6 +30,26 @@ void    usage(char *argv[])
     exit(EX_USAGE);
 }
 
+#ifdef __linux__
+size_t  strlcat(char *dest,const char *src,size_t maxlen)
+
+{
+    char    *dp,*sp;
+    
+    /* Find end of first string */
+    for (dp=dest; (*dp != '\0') && --maxlen; ++dp)
+	;
+    
+    /* Concetanate second string */
+    for (sp=(char *)src; (*sp != '\0') && --maxlen; )
+	*dp++ = *sp++;
+    
+    /* Null terminate */
+    *dp = '\0';
+    return dp-dest;
+}
+#endif
+
 int     main(int argc,char *argv[])
 
 {
