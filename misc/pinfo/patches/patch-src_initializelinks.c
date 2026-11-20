$NetBSD: patch-src_initializelinks.c,v 1.1 2026/11/20 15:57:11 ktnb Exp $

ctype fix for NetBSD 11

--- src/initializelinks.c.orig	2026-11-20 14:30:16.042759124 +0000
+++ src/initializelinks.c
@@ -49,10 +49,10 @@ compare_tag_table_string(char *base, char *compared)
 	{
 		if (base[i] != compared[j])
 		{
-			if ((isspace(compared[j])) &&(isspace(base[i])));	/* OK--two blanks */
-			else if (isspace(compared[j]))
+			if ((isspace((unsigned char)compared[j])) &&(isspace((unsigned char)base[i])));	/* OK--two blanks */
+			else if (isspace((unsigned char)compared[j]))
 				i--;		/* index of `base' should be unchanged after for's i++ */
-			else if (isspace(base[i]))
+			else if (isspace((unsigned char)base[i]))
 				j--;		/* index of `compared' stands in place
 							   and waits for base to skip blanks */
 			else
@@ -62,7 +62,7 @@ compare_tag_table_string(char *base, char *compared)
 	}
 	while (compared[j])		/* handle trailing whitespaces of variable `compared' */
 	{
-		if (!isspace(compared[j]))
+		if (!isspace((unsigned char)compared[j]))
 			return (int) base[i] -(int) compared[j];
 		j++;
 	}
@@ -127,7 +127,7 @@ finddot(char *str, int mynote)
 	};
 	char *closest = 0;
 	int i;
-	while (isspace(*ptr))	/* if there are only spaces and newline... */
+	while (isspace((unsigned char)*ptr))	/* if there are only spaces and newline... */
 	{
 		if (*ptr == '\n')		/* then it's a `Menu:   \n' entry--skip it */
 			return 0;
@@ -449,7 +449,7 @@ handle_no_file_menu_label:
 					}
 
 					start = tmp + 1;	/* move after the padding spaces */
-					while (isspace(*start))
+					while (isspace((unsigned char)*start))
 						start++;
 					NodenameLen =(long)(dot - start);
 					strcpy(hyperobjects[hyperobjectcount].file, "");
@@ -703,7 +703,7 @@ handle_no_file_note_label:
 						}
 
 						start = tmp + 1;	/* move after the padding spaces */
-						while (isspace(*start))
+						while (isspace((unsigned char)*start))
 							start++;
 						NodenameLen =(long)(dot - start);
 						strcpy(hyperobjects[hyperobjectcount].file, "");
