$NetBSD: patch-revision.c,v 1.1.2.2 2016/03/22 18:55:23 bsiegert Exp $

CVE-2016-2324 via Debian
https://security-tracker.debian.org/tracker/CVE-2016-2324
https://github.com/git/git/commit/9831e92bfa833ee9c0ce464bbc2f941ae6c2698d

--- revision.c.orig	2016-03-10 22:11:15.000000000 +0000
+++ revision.c
@@ -25,69 +25,13 @@ volatile show_early_output_fn_t show_ear
 static const char *term_bad;
 static const char *term_good;
 
-char *path_name(const struct name_path *path, const char *name)
+void show_object_with_name(FILE *out, struct object *obj, const char *name)
 {
-	const struct name_path *p;
-	char *n, *m;
-	int nlen = strlen(name);
-	int len = nlen + 1;
-
-	for (p = path; p; p = p->up) {
-		if (p->elem_len)
-			len += p->elem_len + 1;
-	}
-	n = xmalloc(len);
-	m = n + len - (nlen + 1);
-	memcpy(m, name, nlen + 1);
-	for (p = path; p; p = p->up) {
-		if (p->elem_len) {
-			m -= p->elem_len + 1;
-			memcpy(m, p->elem, p->elem_len);
-			m[p->elem_len] = '/';
-		}
-	}
-	return n;
-}
-
-static int show_path_component_truncated(FILE *out, const char *name, int len)
-{
-	int cnt;
-	for (cnt = 0; cnt < len; cnt++) {
-		int ch = name[cnt];
-		if (!ch || ch == '\n')
-			return -1;
-		fputc(ch, out);
-	}
-	return len;
-}
-
-static int show_path_truncated(FILE *out, const struct name_path *path)
-{
-	int emitted, ours;
-
-	if (!path)
-		return 0;
-	emitted = show_path_truncated(out, path->up);
-	if (emitted < 0)
-		return emitted;
-	if (emitted)
-		fputc('/', out);
-	ours = show_path_component_truncated(out, path->elem, path->elem_len);
-	if (ours < 0)
-		return ours;
-	return ours || emitted;
-}
-
-void show_object_with_name(FILE *out, struct object *obj,
-			   const struct name_path *path, const char *component)
-{
-	struct name_path leaf;
-	leaf.up = (struct name_path *)path;
-	leaf.elem = component;
-	leaf.elem_len = strlen(component);
+	const char *p;
 
 	fprintf(out, "%s ", oid_to_hex(&obj->oid));
-	show_path_truncated(out, &leaf);
+	for (p = name; *p && *p != '\n'; p++)
+		fputc(*p, out);
 	fputc('\n', out);
 }
 
