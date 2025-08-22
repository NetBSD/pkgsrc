$NetBSD: patch-source_src_rendertext.cpp,v 1.3 2025/08/22 01:49:47 nia Exp $

Fix ctype usage so guard page isn't hit on netbsd.

--- source/src/rendertext.cpp.orig	2025-08-22 01:46:39.449461825 +0000
+++ source/src/rendertext.cpp
@@ -544,7 +544,7 @@ void encodeigraphs(char *d, const char *
         string mnem;
         loopi(len)
         {
-            if(*s == ':' && (!i || isspace(s[-1])) && i < len - 1)
+            if(*s == ':' && (!i || isspace((unsigned char)s[-1])) && i < len - 1)
             {
                 int l = strcspn(s + 1, " \t\n."), u;
                 if(l && l < MAXSTRLEN)
