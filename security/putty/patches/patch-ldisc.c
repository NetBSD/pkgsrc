$NetBSD: patch-ldisc.c,v 1.3 2019/10/01 15:22:41 ryoon Exp $

pwrite is a standard system call

--- ldisc.c.orig	2019-09-22 09:14:48.000000000 +0000
+++ ldisc.c
@@ -40,7 +40,7 @@ static int plen(Ldisc *ldisc, unsigned c
         return 4;                      /* <XY> hex representation */
 }
 
-static void pwrite(Ldisc *ldisc, unsigned char c)
+static void pwrite_(Ldisc *ldisc, unsigned char c)
 {
     if ((c >= 32 && c <= 126) ||
         (!in_utf(ldisc->term) && c >= 0xA0) ||
@@ -227,7 +227,7 @@ void ldisc_send(Ldisc *ldisc, const void
                     int i;
                     c_write(ldisc, "^R\r\n", 4);
                     for (i = 0; i < ldisc->buflen; i++)
-                        pwrite(ldisc, ldisc->buf[i]);
+                        pwrite_(ldisc, ldisc->buf[i]);
                 }
                 break;
               case CTRL('V'):          /* quote next char */
@@ -292,7 +292,7 @@ void ldisc_send(Ldisc *ldisc, const void
                 sgrowarray(ldisc->buf, ldisc->bufsiz, ldisc->buflen);
                 ldisc->buf[ldisc->buflen++] = c;
                 if (ECHOING)
-                    pwrite(ldisc, (unsigned char) c);
+                    pwrite_(ldisc, (unsigned char) c);
                 ldisc->quotenext = false;
                 break;
             }
