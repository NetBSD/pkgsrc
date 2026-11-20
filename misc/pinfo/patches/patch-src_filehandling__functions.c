$NetBSD: patch-src_filehandling__functions.c,v 1.1 2026/11/20 15:57:11 ktnb Exp $

ctype fix for NetBSD 11; fixed bug with GNU basename(3)

--- src/filehandling_functions.c.orig	2019-02-16 20:23:32.000000000 +0000
+++ src/filehandling_functions.c
@@ -65,10 +65,12 @@ matchfile(char **buf, char *name)
 {
 #define Buf	(*buf)
 	DIR *dir;
-	char *bname = basename(name);
+        char *bname = strrchr(name, '/');
 	struct dirent *dp;
 	int matched = 0;
 
+        bname = bname ? bname + 1 : name;
+
 	/* remove a possible ".info" from the end of the file name
 	 * we're looking for */
 	strip_info_suffix(bname);
@@ -181,7 +183,7 @@ dirpage_lookup(char **type, char ***message, unsigned 
 			file[fileend - filestart - 1] = 0;
 			strncpy(name, fileend + 1, dot - fileend - 1);
 			name[dot - fileend - 1] = 0;
-			while (isspace(*tmp)) tmp++;
+			while (isspace((unsigned char)*tmp)) tmp++;
 
 			if (strlen(name))
 			{
@@ -391,7 +393,7 @@ load_tag_table(char **message, unsigned long lines)
 		char *check;
 		wsk = message[i + is_indirect];
 		check = wsk + strlen(wsk);
-		while (!isspace(*(++wsk)))
+		while (!isspace((unsigned char)*(++wsk)))
 		{
 			if (wsk >= check)
 			{
@@ -757,7 +759,7 @@ openinfo(char *filename, int number)
 	int i, j;
 	char *tmpfilename;
 
-	if ((strncmp(filename, "dir", 3)==0)  &&  !isalnum(filename[3]))
+	if ((strncmp(filename, "dir", 3)==0)  &&  !isalnum((unsigned char)filename[3]))
 	{
 		xfree(buf);
 		return opendirfile(number);
