$NetBSD: patch-Utils_mktext.c,v 1.1 2011/12/19 16:20:56 wiz Exp $

Fix conflict with POSIX getline().

--- Utils/mktext.c.orig	2001-07-09 08:09:10.000000000 +0000
+++ Utils/mktext.c
@@ -61,7 +61,7 @@ void wordlist(void);
 void stringlist(void);
 void ptrlist(void);
 void add_code(u_char);
-char *getline(void);
+char *mgetline(void);
 void parse_label(char *);
 void parse_string(char *);
 void defs(void);
@@ -122,10 +122,10 @@ main(int argc, char *argv[])
 		fprintf(outfp, "\t.word\tT0\n");
 		fprintf(outfp, "\n");
 	}
-	while((line = getline()) != NULL) {
+	while((line = mgetline()) != NULL) {
 		parse_label(line);
 		free(line);
-		if((line = getline()) == NULL)
+		if((line = mgetline()) == NULL)
 			panic("no string after label '%s'", cstr->name);
 		parse_string(line);
 		free(line);
@@ -158,7 +158,7 @@ usage()
 
 
 char *
-getline()
+mgetline()
 {
 	char *line, *p;
 
