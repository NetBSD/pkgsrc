$NetBSD: patch-lib_stackio.c,v 1.1 2026/07/28 21:23:17 wiz Exp $

Fix ctype(3) usage.

--- lib/stackio.c.orig	2026-07-28 21:20:40.501578374 +0000
+++ lib/stackio.c
@@ -439,7 +439,7 @@ char *stackfgets(strbuffer_t *buffer, char *extraincl)
 			eol = bufpastwhitespace + strcspn(bufpastwhitespace, "\r\n"); if (eol) { eolchar = *eol; *eol = '\0'; }
 			newfn = bufpastwhitespace + strcspn(bufpastwhitespace, " \t");
 			newfn += strspn(newfn, " \t");
-			while (*newfn && isspace(*(newfn + strlen(newfn) - 1))) *(newfn + strlen(newfn) -1) = '\0';
+			while (*newfn && isspace((unsigned char)*(newfn + strlen(newfn) - 1))) *(newfn + strlen(newfn) -1) = '\0';
 
 			if (*newfn && (stackfopen(newfn, "r", (void **)fdhead->listhead) != NULL))
 				return stackfgets(buffer, extraincl);
@@ -457,7 +457,7 @@ char *stackfgets(strbuffer_t *buffer, char *extraincl)
 			eol = bufpastwhitespace + strcspn(bufpastwhitespace, "\r\n"); if (eol) { eolchar = *eol; *eol = '\0'; }
 			dirfn = bufpastwhitespace + 9;
 			dirfn += strspn(dirfn, " \t");
-			while (*dirfn && isspace(*(dirfn + strlen(dirfn) - 1))) *(dirfn + strlen(dirfn) -1) = '\0';
+			while (*dirfn && isspace((unsigned char)*(dirfn + strlen(dirfn) - 1))) *(dirfn + strlen(dirfn) -1) = '\0';
 
 			if (*dirfn) addtofnlist(dirfn, optional, (void **)fdhead->listhead);
 			if (fnlist && (stackfopen(fnlist->name, "r", (void **)fdhead->listhead) != NULL)) {
