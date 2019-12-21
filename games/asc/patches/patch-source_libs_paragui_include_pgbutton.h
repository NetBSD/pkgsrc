$NetBSD: patch-source_libs_paragui_include_pgbutton.h,v 1.1 2019/12/21 23:40:43 joerg Exp $

Since GetId() is declared as integer, make sure the constants fit.

--- source/libs/paragui/include/pgbutton.h.orig	2019-12-21 19:52:56.429548693 +0000
+++ source/libs/paragui/include/pgbutton.h
@@ -129,13 +129,13 @@ public:
 	Standard button IDs
 	*/
 	enum {
-	    OK = 0x80000001,
-	    YES = 0x80000002,
-	    NO = 0x80000003,
-	    APPLY = 0x80000004,
-	    CANCEL = 0x80000005,
-	    CLOSE = 0x80000006,
-	    HELP = 0x80000007
+	    OK = 0x70000001,
+	    YES = 0x70000002,
+	    NO = 0x70000003,
+	    APPLY = 0x70000004,
+	    CANCEL = 0x70000005,
+	    CLOSE = 0x70000006,
+	    HELP = 0x70000007
 	};
 
 	/**
