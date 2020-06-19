$NetBSD: patch-action.c,v 1.2 2020/06/19 21:17:46 scole Exp $

Do not use alloca and strdupa which some platforms may not have

--- action.c.orig	2019-08-29 01:58:04.000000000 +0000
+++ action.c
@@ -2284,9 +2284,22 @@ static char *get_start(char *s, int n)
 
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
 
 /*
