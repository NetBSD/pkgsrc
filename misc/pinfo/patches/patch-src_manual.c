$NetBSD: patch-src_manual.c,v 1.1 2026/11/20 15:57:11 ktnb Exp $

ctype fix for NetBSD 11

--- src/manual.c.orig	2026-11-20 14:21:55.644146177 +0000
+++ src/manual.c
@@ -158,14 +158,14 @@ set_initial_history(char *name)
 	/* one object of array */
 	manualhistory = xmalloc(sizeof(manhistory));
 	/* filter trailing spaces */
-	while ((len > 1) &&(isspace(name1[len - 1])))
+	while ((len > 1) &&(isspace((unsigned char)name1[len - 1])))
 	{
 		name1[len - 1] = 0;
 		len--;
 	}
 	i = len;
 	/* find the beginning of the last token */
-	for (i = len - 1;(i > 0) &&(!isspace(name1[i])); i--);
+	for (i = len - 1;(i > 0) &&(!isspace((unsigned char)name1[i])); i--);
 
 	/* if we've found space, then we move to the first nonspace character */
 	if (i > 0)
@@ -234,7 +234,7 @@ construct_manualname(char *buf, int which)
 			strncpy(base, manual[manuallinks[which].line - 1],1023);
 			strip_manual(base);
 			ptr = base + strlen(base) - 3;
-			while (((isalpha(*ptr)) ||(*ptr == '.') ||(*ptr == '_')) &&(ptr > base))
+			while (((isalpha((unsigned char)*ptr)) ||(*ptr == '.') ||(*ptr == '_')) &&(ptr > base))
 				ptr--;
 			/* workaround for man pages with leading '(' see svgalib man pages */
 			if (*ptr == '(')
@@ -256,7 +256,7 @@ construct_manualname(char *buf, int which)
 			strip_manual(base);
 			ptr = base;
 			/* skip whitespace */
-			while (isspace(*ptr))
+			while (isspace((unsigned char)*ptr))
 				ptr++;
 			eptr = findurlend(ptr);
 			*eptr = 0;
@@ -700,7 +700,7 @@ loadmanual(FILE * id)
 			man_initializelinks(tmp, carryflag);
 			carryflag = 0;
 			if (manlinelen > 1)
-				if (ishyphen(manual[ManualLines][manlinelen - 2]))
+				if (ishyphen((unsigned char)manual[ManualLines][manlinelen - 2]))
 					carryflag = 1;
 			/* free temporary buffer */
 			xfree(tmp);
@@ -757,7 +757,7 @@ man_initializelinks(char *tmp, int carry)
 		manuallinks[ManualLinks].name = xmalloc(urlend - urlstart + 10);
 		strncpy(manuallinks[ManualLinks].name, urlstart, urlend - urlstart);
 		manuallinks[ManualLinks].name[urlend - urlstart] = 0;
-		if (ishyphen(manuallinks[ManualLinks].name[urlend - urlstart - 1]))
+		if (ishyphen((unsigned char)manuallinks[ManualLinks].name[urlend - urlstart - 1]))
 			manuallinks[ManualLinks].carry = 1;
 		else
 			manuallinks[ManualLinks].carry = 0;
@@ -776,7 +776,7 @@ man_initializelinks(char *tmp, int carry)
 		manuallinks[ManualLinks].name = xmalloc(urlend - urlstart + 10);
 		strncpy(manuallinks[ManualLinks].name, urlstart, urlend - urlstart);
 		manuallinks[ManualLinks].name[urlend - urlstart] = 0;
-		if (ishyphen(manuallinks[ManualLinks].name[urlend - urlstart - 1]))
+		if (ishyphen((unsigned char)manuallinks[ManualLinks].name[urlend - urlstart - 1]))
 			manuallinks[ManualLinks].carry = 1;
 		else
 			manuallinks[ManualLinks].carry = 0;
@@ -795,7 +795,7 @@ man_initializelinks(char *tmp, int carry)
 		manuallinks[ManualLinks].name = xmalloc(urlend - urlstart + 10);
 		strncpy(manuallinks[ManualLinks].name, urlstart, urlend - urlstart);
 		manuallinks[ManualLinks].name[urlend - urlstart] = 0;
-		if (ishyphen(manuallinks[ManualLinks].name[urlend - urlstart - 1]))
+		if (ishyphen((unsigned char)manuallinks[ManualLinks].name[urlend - urlstart - 1]))
 			manuallinks[ManualLinks].carry = 1;
 		else
 			manuallinks[ManualLinks].carry = 0;
@@ -833,7 +833,7 @@ man_initializelinks(char *tmp, int carry)
 						i++;
 					for (; i > 0; --i)
 					{
-						if (!isspace(tmp[i]))
+						if (!isspace((unsigned char)tmp[i]))
 							/* ignore spaces between linkname and '(x)' */
 							break;
 					}
@@ -848,7 +848,7 @@ man_initializelinks(char *tmp, int carry)
 					 */
 					for (i = breakpos; i > 0; --i)
 					{
-						if (isspace(tmp[i]))
+						if (isspace((unsigned char)tmp[i]))
 						{
 							i++;
 							break;
@@ -884,7 +884,7 @@ man_initializelinks(char *tmp, int carry)
 					if (LongManualLinks)
 					{
 						for (b = 1; mylink[b] != ')'; b++)
-							manuallinks[ManualLinks].section[b - 1] = tolower(mylink[b]);
+							manuallinks[ManualLinks].section[b - 1] = tolower((unsigned char)mylink[b]);
 						manuallinks[ManualLinks].section[b - 1] = 0;
 					}
 					else
@@ -903,7 +903,7 @@ man_initializelinks(char *tmp, int carry)
 					for (b = i - 1; b >= 0; b--)
 					{
 						if (b > 0)
-							if (!isspace(tmp[b]))
+							if (!isspace((unsigned char)tmp[b]))
 								break;
 					}
 					if (b >= 0)
@@ -1065,7 +1065,7 @@ manualwork()
 					int digit_val = 1;
 					for (unsigned i = 0; token[i] != 0; i++)
 					{
-						if (!isdigit(token[i]))
+						if (!isdigit((unsigned char)token[i]))
 							digit_val = 0;
 					}
 					/* move cursor position */
@@ -1812,7 +1812,7 @@ add_highlights()
 						 * positon ltlinelen to the beginning of the link to be
 						 * highlighted
 						 */
-						while ((isalpha(TestCh)) ||(TestCh == '.') ||(TestCh == '_'))
+						while ((isalpha((unsigned char)TestCh)) ||(TestCh == '.') ||(TestCh == '_'))
 							ltlinelen--;
 
 						*newlinemark = 0;
@@ -1853,7 +1853,7 @@ add_highlights()
 					char *wskend;
 					strip_manual(tmpstr);
 					/* skip spaces */
-					while (isspace(tmpstr[k]))
+					while (isspace((unsigned char)tmpstr[k]))
 						k++;
 					/* find the end of url */
 					wskend = findurlend(tmpstr+k);
