$NetBSD: patch-macro.c,v 1.1 2015/06/13 00:10:12 dholland Exp $

Upstream patch: don't use "remove" as a local variable as gcc 4.1 gets
upset about it vs. remove(3) in stdio.h.

diff -r 6947cd2cde79 macro.c
--- macro.c	Fri Jun 12 20:06:09 2015 -0400
+++ macro.c	Fri Jun 12 20:06:18 2015 -0400
@@ -340,7 +340,7 @@
 
 static
 struct macro *
-macrotable_findlen(const char *name, size_t len, bool remove)
+macrotable_findlen(const char *name, size_t len, bool remove_it)
 {
 	unsigned hash;
 	struct macroarray *bucket;
@@ -361,7 +361,7 @@
 		}
 		mlen = strlen(m->name);
 		if (len == mlen && !memcmp(name, m->name, len)) {
-			if (remove) {
+			if (remove_it) {
 				if (i < num-1) {
 					m2 = macroarray_get(bucket, num-1);
 					macroarray_set(bucket, i, m2);
@@ -377,9 +377,9 @@
 
 static
 struct macro *
-macrotable_find(const char *name, bool remove)
+macrotable_find(const char *name, bool remove_it)
 {
-	return macrotable_findlen(name, strlen(name), remove);
+	return macrotable_findlen(name, strlen(name), remove_it);
 }
 
 static
