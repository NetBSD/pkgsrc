$NetBSD$

Cast argument (gcc says "unsigned int") to match %lu format.
https://bugzilla.gnome.org/show_bug.cgi?id=766839

--- timsort.h.orig	2016-02-09 10:17:34.000000000 +0000
+++ timsort.h
@@ -323,7 +323,7 @@ static void TIM_SORT_RESIZE(TEMP_STORAGE
     SORT_TYPE *tempstore = (SORT_TYPE *)realloc(store->storage, new_size * sizeof(SORT_TYPE));
     if (tempstore == NULL)
     {
-      fprintf(stderr, "Error allocating temporary storage for tim sort: need %lu bytes", sizeof(SORT_TYPE) * new_size);
+      fprintf(stderr, "Error allocating temporary storage for tim sort: need %lu bytes", (unsigned long)(sizeof(SORT_TYPE) * new_size));
       exit(1);
     }
     store->storage = tempstore;
