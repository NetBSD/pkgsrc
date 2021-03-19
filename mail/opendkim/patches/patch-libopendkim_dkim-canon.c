$NetBSD: patch-libopendkim_dkim-canon.c,v 1.1 2021/03/19 09:50:21 manu Exp $

--- libopendkim/dkim-canon.c.orig	2021-03-18 09:50:14.195951232 +0100
+++ libopendkim/dkim-canon.c	2021-03-19 09:49:52.141301747 +0100
@@ -386,10 +386,14 @@
 				break;
 			}
 		}
 
-		/* skip all spaces before first word */
-		while (*p != '\0' && DKIM_ISWSP(*p))
+		/*
+		 * skip all spaces before first word 
+		 * we also need to skip CRLF for long header formatted as
+		 * Header-Name:\r\n\tHeader-value
+		 */
+		while (*p != '\0' && DKIM_ISLWSP(*p))
 			p++;
 
 		space = FALSE;				/* just saw a space */
 
