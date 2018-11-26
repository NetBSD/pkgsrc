$NetBSD: patch-src_spell.c,v 1.1 2018/11/26 09:15:53 fox Exp $

1. Replaced int with uint64_t to avoid truncating pointer to (32bit)
   int by using a wider type.
2. Replaced pointer to int type cast with a macro PTR_TO_UINT64(x) to
   help convert the pointer to uint64_t.

This prevents the segfault on startup in amd64 systems.

--- src/spell.c.orig	2003-03-09 17:29:01.000000000 +0000
+++ src/spell.c
@@ -68,7 +68,7 @@ static void spell_node (Node *node)
 		ui_init ();
 }
 
-static int spell_cmd (int argc, char **argv, void *data)
+static uint64_t spell_cmd (int argc, char **argv, void *data)
 {
 	Node *pos = (Node *) data;
 
@@ -85,7 +85,7 @@ static int spell_cmd (int argc, char **a
 	} else {
 		spell_node (pos);
 	}
-	return (int) pos;
+	return PTR_TO_UINT64(pos);
 }
 
 /*
