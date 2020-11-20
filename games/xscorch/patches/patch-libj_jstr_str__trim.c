$NetBSD: patch-libj_jstr_str__trim.c,v 1.1 2020/11/20 15:15:24 nia Exp $

Use memmove() instead of memcpy() for overlapping memory.

From Debian:
https://sources.debian.org/patches/xscorch/0.2.1-1+nmu5/overlapping-memcpy/

--- libj/jstr/str_trim.c.orig	2009-04-26 17:39:30.000000000 +0000
+++ libj/jstr/str_trim.c
@@ -47,7 +47,7 @@ char *trim(char *s) {
       SET_LAST_NWS(ws, s);
 
       /* Copy the non-ws characters in <s>. */
-      if(ws.fnws > d) MEMCPY(d, ws.fnws, NWS_SIZE(ws));
+      if(ws.fnws > d) MEMMOVE(d, ws.fnws, NWS_SIZE(ws));
       *(d + NWS_SIZE(ws)) = '\0';
       return(d);
 
@@ -93,7 +93,7 @@ char *ltrim(char *s) {
 
    if(s != NULL) {
       SKIM_WHITESPACE(s);
-      MEMCPY(d, s, STRLEN(s) + 1);
+      MEMMOVE(d, s, STRLEN(s) + 1);
       return(d);
    }
    return(NULL);
