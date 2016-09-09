$NetBSD: patch-action.c,v 1.1 2016/09/09 15:40:17 scole Exp $
Do not use alloca and strdupa which some platforms may not have

--- action.c.orig	2014-05-10 04:54:13.000000000 +0000
+++ action.c
@@ -43,6 +43,7 @@
 #include "mksquashfs.h"
 #include "action.h"
 #include "error.h"
+#include "fnm_extmatch.h"
 
 /*
  * code to parse actions
@@ -1953,9 +1954,22 @@ static char *get_start(char *s, int n)
 
 static int subpathname_fn(struct atom *atom, struct action_data *action_data)
 {
-	return fnmatch(atom->argv[0], get_start(strdupa(action_data->subpath),
+	/* XXX some platforms might not have alloca, strdupa */
+	int ret_val;
+	char *copy_str;
+
+	if ((copy_str = strdup(action_data->subpath)) == NULL) {
+	  fprintf(stderr, "Out of mem\n");
+	  exit(1);
+	}
+
+	ret_val = fnmatch(atom->argv[0],get_start(copy_str,
 		count_components(atom->argv[0])),
 		FNM_PATHNAME|FNM_PERIOD|FNM_EXTMATCH) == 0;
+
+	free(copy_str);
+
+	return ret_val;
 }
 
 TEST_VAR_FN(filesize, ACTION_REG, action_data->buf->st_size)
