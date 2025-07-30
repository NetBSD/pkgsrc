$NetBSD: patch-tag.c,v 1.1 2025/07/30 13:21:45 wiz Exp $

Revisions 1.37 and 1.38 from upstream.

--- tag.c.orig	2021-09-23 18:03:23.000000000 +0000
+++ tag.c
@@ -2,3 +2,4 @@
 /*
- * Copyright (c) 2015,2016,2018,2019,2020 Ingo Schwarze <schwarze@openbsd.org>
+ * Copyright (c) 2015, 2016, 2018, 2019, 2020, 2022, 2023
+ *               Ingo Schwarze <schwarze@openbsd.org>
  *
@@ -27,2 +28,3 @@
 #include <stdint.h>
+#include <stdio.h>
 #include <stdlib.h>
@@ -32,2 +34,3 @@
 #include "mandoc_ohash.h"
+#include "mandoc.h"
 #include "roff.h"
@@ -82,3 +85,3 @@ tag_free(void)
  * Set a node where a term is defined,
- * unless it is already defined at a lower priority.
+ * unless the term is already defined at a lower priority.
  */
@@ -89,5 +92,7 @@ tag_put(const char *s, int prio, struct 
 	struct roff_node	*nold;
-	const char		*se;
+	const char		*se, *src;
+	char			*cpy;
 	size_t			 len;
 	unsigned int		 slot;
+	int			 changed;
 
@@ -95,2 +100,15 @@ tag_put(const char *s, int prio, struct 
 
+	/*
+	 * If the node is already tagged, the existing tag is
+	 * explicit and we are now about to add an implicit tag.
+	 * Don't do that; just skip implicit tagging if the author
+	 * specified an explicit tag.
+	 */
+
+	if (n->flags & NODE_ID)
+		return;
+
+	/* Determine the implicit tag. */
+
+	changed = 1;
 	if (s == NULL) {
@@ -111,3 +129,3 @@ tag_put(const char *s, int prio, struct 
 			default:
-				break;
+				return;
 			}
@@ -115,2 +133,3 @@ tag_put(const char *s, int prio, struct 
 		default:
+			changed = 0;
 			break;
@@ -120,2 +139,3 @@ tag_put(const char *s, int prio, struct 
 	/*
+	 * Translate \- and ASCII_HYPH to plain '-'.
 	 * Skip whitespace and escapes and whatever follows,
@@ -124,10 +144,34 @@ tag_put(const char *s, int prio, struct 
 
-	len = strcspn(s, " \t\\");
+	cpy = mandoc_malloc(strlen(s) + 1);
+	for (src = s, len = 0; *src != '\0'; src++, len++) {
+		switch (*src) {
+		case '\t':
+		case ' ':
+			changed = 1;
+			break;
+		case ASCII_HYPH:
+			cpy[len] = '-';
+			changed = 1;
+			continue;
+		case '\\':
+			if (src[1] != '-')
+				break;
+			src++;
+			changed = 1;
+			/* FALLTHROUGH */
+		default:
+			cpy[len] = *src;
+			continue;
+		}
+		break;
+	}
 	if (len == 0)
-		return;
+		goto out;
+	cpy[len] = '\0';
 
-	se = s + len;
-	if (*se != '\0' && prio < TAG_WEAK)
+	if (*src != '\0' && prio < TAG_WEAK)
 		prio = TAG_WEAK;
 
+	s = cpy;
+	se = cpy + len;
 	slot = ohash_qlookupi(&tag_data, s, &se);
@@ -139,4 +183,3 @@ tag_put(const char *s, int prio, struct 
 		entry = mandoc_malloc(sizeof(*entry) + len + 1);
-		memcpy(entry->s, s, len);
-		entry->s[len] = '\0';
+		memcpy(entry->s, s, len + 1);
 		entry->nodes = NULL;
@@ -152,3 +195,3 @@ tag_put(const char *s, int prio, struct 
 	else if (entry->prio < prio)
-			return;
+		goto out;
 
@@ -169,3 +212,3 @@ tag_put(const char *s, int prio, struct 
 			entry->prio = TAG_DELETE;
-			return;
+			goto out;
 		}
@@ -183,3 +226,3 @@ tag_put(const char *s, int prio, struct 
 	n->flags |= NODE_ID;
-	if (n->child == NULL || n->child->string != s || *se != '\0') {
+	if (changed) {
 		assert(n->tag == NULL);
@@ -187,2 +230,5 @@ tag_put(const char *s, int prio, struct 
 	}
+
+ out:
+	free(cpy);
 }
