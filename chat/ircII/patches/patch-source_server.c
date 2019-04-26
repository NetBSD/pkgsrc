$NetBSD: patch-source_server.c,v 1.1 2019/04/26 00:12:14 mrg Exp $

- Don't free data that came from the environment.

Index: source/server.c
===================================================================
RCS file: /home/cvs/ircii/source/server.c,v
retrieving revision 1.245
retrieving revision 1.246
diff -p -u -r1.245 -r1.246
--- source/server.c	5 Feb 2019 01:35:49 -0000	1.245
+++ source/server.c	26 Apr 2019 00:08:33 -0000	1.246
@@ -1796,17 +1796,19 @@ read_server_file(void)
 {
 	FILE *fp;
 	u_char format[11];
-	u_char *file_path = NULL;
+	u_char *file_path;
+	u_char *free_path = NULL;
 	u_char	buffer[FS_BUFFER_SIZE];
 
 	if ((file_path = my_getenv("IRCSERVERSFILE")) == NULL)
 	{
-		malloc_strcpy(&file_path, my_irc_lib());
-		malloc_strcat(&file_path, UP(SERVERS_FILE));
+		malloc_strcpy(&free_path, my_irc_lib());
+		malloc_strcat(&free_path, UP(SERVERS_FILE));
+		file_path = free_path;
 	}
 	snprintf(CP(format), sizeof format, "%%%ds", (int)sizeof buffer);
 	fp = fopen(CP(file_path), "r");
-	new_free(&file_path);
+	new_free(&free_path);
 	if (NULL != fp)
 	{
 		while (fscanf(fp, CP(format), buffer) != EOF)
