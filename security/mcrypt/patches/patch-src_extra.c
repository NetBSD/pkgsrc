$NetBSD: patch-src_extra.c,v 1.1.2.2 2018/06/17 11:40:03 spz Exp $

* Fix buffer overflow when decrypting a file with a too long salt.
  (CVE-2012-4409)
* Fix other potential buffer overflows in check_file_head.
  (No vulnerability Id)

  From: Debian, Red Hat, SUSE

--- src/extra.c.orig	2007-11-07 17:10:20.000000000 +0000
+++ src/extra.c
@@ -223,7 +223,8 @@ int check_file_head(FILE * fstream, char
 		}
 
 		read_until_null(tmp_buf, fstream);
-		strcpy(algorithm, tmp_buf);
+		strncpy(algorithm, tmp_buf, 50);
+		algorithm[49] = '\0';
 
 		fread(&keylen, sizeof(short int), 1, fstream);
 #ifdef WORDS_BIGENDIAN
@@ -233,15 +234,19 @@ int check_file_head(FILE * fstream, char
 #endif
 
 		read_until_null(tmp_buf, fstream);
-		strcpy(mode, tmp_buf);
+		strncpy(mode, tmp_buf, 50);
+		mode[49] = '\0';
 
 		read_until_null(tmp_buf, fstream);
-		strcpy(keymode, tmp_buf);
+		strncpy(keymode, tmp_buf, 50);
+		keymode[49] = '\0';
 		fread(&sflag, 1, 1, fstream);
 		if (m_getbit(6, flags) == 1) { /* if the salt bit is set */
 			if (m_getbit(0, sflag) != 0) { /* if the first bit is set */
 				*salt_size = m_setbit(0, sflag, 0);
 				if (*salt_size > 0) {
+					if (*salt_size > sizeof(tmp_buf))
+						err_quit(_("Salt is too long\n"));
 					fread(tmp_buf, 1, *salt_size,
 					      fstream);
 					memmove(salt, tmp_buf, *salt_size);
@@ -503,6 +508,7 @@ char **read_key_file(char *file, int *nu
 	}
 
 	*num = x;
+	fclose(FROMF);
 
 	return keys;
 
