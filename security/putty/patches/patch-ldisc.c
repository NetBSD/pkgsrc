$NetBSD: patch-ldisc.c,v 1.1.2.2 2012/02/23 15:53:56 tron Exp $

pwrite is a standard system call

--- ldisc.c.orig	2010-09-09 14:32:25.000000000 +0000
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
