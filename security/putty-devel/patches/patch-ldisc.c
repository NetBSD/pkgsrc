$NetBSD: patch-ldisc.c,v 1.1 2011/12/05 22:55:36 joerg Exp $

--- ldisc.c.orig	2011-12-05 21:43:46.000000000 +0000
+++ ldisc.c
@@ -41,7 +41,7 @@ static int plen(Ldisc ldisc, unsigned ch
 	return 4;		       /* <XY> hex representation */
 }
 
-static void pwrite(Ldisc ldisc, unsigned char c)
+static void pwrite_(Ldisc ldisc, unsigned char c)
 {
     if ((c >= 32 && c <= 126) ||
 	(!in_utf(ldisc->term) && c >= 0xA0) ||
@@ -217,7 +217,7 @@ void ldisc_send(void *handle, char *buf,
 		    int i;
 		    c_write(ldisc, "^R\r\n", 4);
 		    for (i = 0; i < ldisc->buflen; i++)
-			pwrite(ldisc, ldisc->buf[i]);
+			pwrite_(ldisc, ldisc->buf[i]);
 		}
 		break;
 	      case CTRL('V'):	       /* quote next char */
@@ -284,7 +284,7 @@ void ldisc_send(void *handle, char *buf,
 		}
 		ldisc->buf[ldisc->buflen++] = c;
 		if (ECHOING)
-		    pwrite(ldisc, (unsigned char) c);
+		    pwrite_(ldisc, (unsigned char) c);
 		ldisc->quotenext = FALSE;
 		break;
 	    }
