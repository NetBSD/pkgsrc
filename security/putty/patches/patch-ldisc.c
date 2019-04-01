$NetBSD: patch-ldisc.c,v 1.2 2019/04/01 12:10:43 ryoon Exp $

pwrite is a standard system call

--- ldisc.c.orig	2019-03-16 12:26:34.000000000 +0000
+++ ldisc.c
@@ -42,7 +42,7 @@ static int plen(Ldisc *ldisc, unsigned c
 	return 4;		       /* <XY> hex representation */
 }
 
-static void pwrite(Ldisc *ldisc, unsigned char c)
+static void pwrite_(Ldisc *ldisc, unsigned char c)
 {
     if ((c >= 32 && c <= 126) ||
 	(!in_utf(ldisc->term) && c >= 0xA0) ||
@@ -229,7 +229,7 @@ void ldisc_send(Ldisc *ldisc, const void
 		    int i;
 		    c_write(ldisc, "^R\r\n", 4);
 		    for (i = 0; i < ldisc->buflen; i++)
-			pwrite(ldisc, ldisc->buf[i]);
+			pwrite_(ldisc, ldisc->buf[i]);
 		}
 		break;
 	      case CTRL('V'):	       /* quote next char */
@@ -294,7 +294,7 @@ void ldisc_send(Ldisc *ldisc, const void
                 sgrowarray(ldisc->buf, ldisc->bufsiz, ldisc->buflen);
 		ldisc->buf[ldisc->buflen++] = c;
 		if (ECHOING)
-		    pwrite(ldisc, (unsigned char) c);
+		    pwrite_(ldisc, (unsigned char) c);
 		ldisc->quotenext = false;
 		break;
 	    }
