$NetBSD: patch-js_src_yarr_pcre_pcre.h,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- js/src/yarr/pcre/pcre.h.orig	2012-03-09 22:20:24.000000000 +0000
+++ js/src/yarr/pcre/pcre.h
@@ -46,7 +46,9 @@ POSSIBILITY OF SUCH DAMAGE.
 #include "assembler/wtf/Platform.h"
 #include "jsstr.h"
 #include "jsprvtd.h"
+#if ENABLE_ASSEMBLER
 #include "jstl.h"
+#endif
 
 typedef jschar UChar;
 typedef JSLinearString UString;
