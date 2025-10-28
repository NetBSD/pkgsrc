$NetBSD: patch-src_bin_edje__player.c,v 1.1 2025/10/28 00:24:02 gutteridge Exp $

Use ctype.h correctly.

--- src/bin/edje_player.c.orig	2013-07-30 14:42:43.000000000 +0000
+++ src/bin/edje_player.c
@@ -58,7 +58,7 @@ _slave_mode_tok(char **p_arg)
    if (!*p_arg) return NULL;
 
    s = *p_arg;
-   while (isspace(*s))
+   while (isspace((unsigned char)*s))
      s++;
 
    if (*s == '\0')
@@ -80,7 +80,7 @@ _slave_mode_tok(char **p_arg)
 
    for (e = s; *e != '\0'; e++)
      {
-	if ((!is_quoted) && (isspace(*e)))
+	if ((!is_quoted) && (isspace((unsigned char)*e)))
 	  break;
 	else if ((is_quoted) && (*e == '"'))
 	  break;
@@ -223,7 +223,7 @@ _slave_mode(void *data, Ecore_Fd_Handler
 	*p = '\0';
 	p++;
 
-	while (isspace(*p))
+	while (isspace((unsigned char)*p))
 	  p++;
 	if (*p == '\0')
 	  p = NULL;
@@ -231,7 +231,7 @@ _slave_mode(void *data, Ecore_Fd_Handler
 	if (p)
 	  {
 	     char *q = p + strlen(p) - 1;
-	     while (isspace(*q))
+	     while (isspace((unsigned char)*q))
 	       {
 		  *q = '\0';
 		  q--;
