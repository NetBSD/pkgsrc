$NetBSD: patch-init.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- init.c.orig	2026-05-16 21:27:11.065781780 +0000
+++ init.c
@@ -10,7 +10,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <stdio.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "articles.h"
@@ -112,7 +112,7 @@ strip_str(register char *cmd)
     if (cmd == NULL)
 	return cmd;
 
-    while (*cmd && isascii(*cmd) && isspace(*cmd))
+    while (*cmd && ISASCII(*cmd) && ISSPACE(*cmd))
 	cmd++;
     if (*cmd == NUL || *cmd == NL)
 	return NULL;
@@ -153,7 +153,7 @@ argv(int i)
 	if (argvec[argc]) {
 	    cmd = argvec[argc];
 	    while (argc <= i) {
-		while (*cmd && (!isascii(*cmd) || !isspace(*cmd)))
+		while (*cmd && (!ISASCII(*cmd) || !ISSPACE(*cmd)))
 		    cmd++;
 		if (*cmd == NUL) {
 		    argc = MAXARG;
@@ -768,7 +768,7 @@ do_map(FILE * initf)
 	    dump_multi_keys();
 	    return 1;
 	}
-	if (isdigit(argv(1)[1]))
+	if (ISDIGIT(argv(1)[1]))
 	    bind_to = K_function(argv(1)[1] - '0');
 	else {
 	    bind_to = parse_key(argv(1) + 1);
@@ -1029,7 +1029,7 @@ parse_on_to_end(FILE * f)
 
 skip_to_end:
     while (fgets_multi(buf, 1024, f)) {
-	for (cp = buf; *cp && isascii(*cp) && isspace(*cp); cp++);
+	for (cp = buf; *cp && ISASCII(*cp) && ISSPACE(*cp); cp++);
 	if (*cp != 'e')
 	    continue;
 	if (strncmp(cp, "end", 3) == 0)
