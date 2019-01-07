$NetBSD: patch-utility_objectStore.C,v 1.1 2019/01/07 02:33:17 bacon Exp $

# NetBSD does not provide WEXITED
# Empty bitmask should suffice in this case

--- utility/objectStore.C.orig	2018-12-23 01:57:06.000000000 +0000
+++ utility/objectStore.C
@@ -286,6 +286,11 @@ fetchFromObjectStore(char *requested) {
   //  Otherwise, we're still the parent, so wait for the (-1 == any) child
   //  process to terminate.
 
+// NetBSD does not provide WEXITED so send empty bitmask
+#ifdef __NetBSD__
+#define	WEXITED	0
+#endif
+
   waitpid(-1, &err, WEXITED);
 
   if ((WIFEXITED(err)) &&
