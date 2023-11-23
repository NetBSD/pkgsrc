$NetBSD: patch-alsaucm_dump.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- alsaucm/dump.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ alsaucm/dump.c
@@ -93,7 +93,8 @@ static char *tesc(const char *s, char *b
 
 #define ESC(s, esc) tesc((s), (esc), sizeof(esc))
 
-static int text_verb_start(struct renderer *, const char *verb, const char *comment)
+static int text_verb_start(struct renderer *r ATTRIBUTE_UNUSED,
+			   const char *verb, const char *comment)
 {
 	char buf1[128], buf2[128];
 	printf("Verb.%s {\n", ESC(verb, buf1));
@@ -102,13 +103,13 @@ static int text_verb_start(struct render
 	return 0;
 }
 
-static int text_verb_end(struct renderer *)
+static int text_verb_end(struct renderer *r ATTRIBUTE_UNUSED)
 {
 	printf("}\n");
 	return 0;
 }
 
-static int text_2nd_level_begin(struct renderer *,
+static int text_2nd_level_begin(struct renderer *r ATTRIBUTE_UNUSED,
 				const char *key,
 				const char *val,
 				const char *comment)
@@ -120,19 +121,19 @@ static int text_2nd_level_begin(struct r
 	return 0;
 }
 
-static int text_2nd_level_end(struct renderer *)
+static int text_2nd_level_end(struct renderer *r ATTRIBUTE_UNUSED)
 {
 	printf("\t}\n");
 	return 0;
 }
 
-static int text_2nd_level(struct renderer *, const char *txt)
+static int text_2nd_level(struct renderer *r ATTRIBUTE_UNUSED, const char *txt)
 {
 	printf("\t\t%s", txt);
 	return 0;
 }
 
-static int text_3rd_level(struct renderer *, const char *txt)
+static int text_3rd_level(struct renderer *r ATTRIBUTE_UNUSED, const char *txt)
 {
 	printf("\t\t\t%s", txt);
 	return 0;
@@ -266,7 +267,7 @@ static void json_block(struct renderer *
 	j->block[level] = last ? 0 : 1;
 }
 
-static int json_init(struct renderer *)
+static int json_init(struct renderer *r ATTRIBUTE_UNUSED)
 {
 	printf("{\n  \"Verbs\": {");
 	return 0;
@@ -325,13 +326,13 @@ static int json_2nd_level_end(struct ren
 	return 0;
 }
 
-static int json_2nd_level(struct renderer *, const char *txt)
+static int json_2nd_level(struct renderer *r ATTRIBUTE_UNUSED, const char *txt)
 {
 	printf("          %s", txt);
 	return 0;
 }
 
-static int json_3rd_level(struct renderer *, const char *txt)
+static int json_3rd_level(struct renderer *r ATTRIBUTE_UNUSED, const char *txt)
 {
 	printf("            %s", txt);
 	return 0;
@@ -360,7 +361,8 @@ static int json_supcon_start(struct rend
 	return 0;
 }
 
-static int json_supcon_value(struct renderer *r, const char *value, int)
+static int json_supcon_value(struct renderer *r, const char *value,
+			     int last ATTRIBUTE_UNUSED)
 {
 	char buf[256];
 	JESC(value, buf);
