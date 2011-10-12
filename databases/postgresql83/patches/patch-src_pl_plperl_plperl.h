--- src/pl/plperl/plperl.h.orig	2011-09-23 00:06:36.000000000 +0200
+++ src/pl/plperl/plperl.h	2011-10-12 20:45:49.478595625 +0200
@@ -26,12 +26,22 @@
 #endif
 #endif
 
+#ifdef __sun
+#define list_head sun_list_head
+#define list_tail sun_list_tail
+#endif
+
 /* required for perl API */
 #include "EXTERN.h"
 #include "perl.h"
 #include "XSUB.h"
 #include "ppport.h"
 
+#ifdef __sun
+#undef list_head
+#undef list_tail
+#endif
+
 /* just in case these symbols aren't provided */
 #ifndef pTHX_
 #define pTHX_
