$NetBSD: patch-LCDIS.H,v 1.1 2018/05/21 16:12:14 minskim Exp $

No stricmp/strnicmp on NetBSD (and most other OSes),
define as strcasecmp/strncasecmp instead.

--- LCDIS.H.orig	2000-07-02 19:43:34.000000000 +0000
+++ LCDIS.H
@@ -17,7 +17,8 @@ void print_code_label (int addr, int for
 int  checkmem(void);
 void search_text (int memsize);
 
-
+#define stricmp(x,y) strcasecmp(x,y)
+#define strnicmp(x,y,z) strncasecmp(x,y,z)
 
 //---0---- ---1---- --2,3--- --4-7--- --8-F---
 
@@ -391,4 +392,4 @@ firmwarecall_type FIRMWARECALL[] =
 // not included     mapmem (0x108); // unknown
 //     mapmem (0x140); // unknown
       {   -1,     -1}   // end of list
-   };
\ No newline at end of file
+   };
