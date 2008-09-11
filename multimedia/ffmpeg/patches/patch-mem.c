$NetBSD: patch-mem.c,v 1.1 2008/09/11 12:08:41 joerg Exp $

--- libavutil/mem.c.orig	2008-05-23 14:37:52.000000000 +0200
+++ libavutil/mem.c
@@ -85,6 +85,9 @@ void *av_malloc(unsigned int size)
 
         btw, malloc seems to do 8 byte alignment by default here
      */
+#elif defined (HAVE_MEMALIGN)
+    if (posix_memalign(&ptr, 16, size))
+	    return NULL;
 #else
     ptr = malloc(size);
 #endif
@@ -95,6 +98,8 @@ void *av_realloc(void *ptr, unsigned int
 {
 #ifdef CONFIG_MEMALIGN_HACK
     int diff;
+#elif defined (HAVE_MEMALIGN)
+    void *new_ptr;
 #endif
 
     /* let's disallow possible ambiguous cases */
@@ -106,6 +111,18 @@ void *av_realloc(void *ptr, unsigned int
     if(!ptr) return av_malloc(size);
     diff= ((char*)ptr)[-1];
     return (char*)realloc((char*)ptr - diff, size + diff) + diff;
+#elif defined (HAVE_MEMALIGN)
+    new_ptr = realloc(ptr, size);
+    if (((size_t)new_ptr & 15) == 0)
+	    return new_ptr;
+
+    if (posix_memalign(&ptr, 16, size)) {
+	    free(new_ptr);
+	    return NULL;
+    }
+    memcpy(ptr, new_ptr, size);
+    free(new_ptr);
+    return ptr;
 #else
     return realloc(ptr, size);
 #endif
