$NetBSD: patch-texk_dvipsk_color.c,v 1.1 2017/10/31 08:12:11 dbj Exp $

The strcpy stack checker in recent versions of clang get confused
and abort when it appears to copy past the end of the structure,
so be explicit about the variable structure field.

Reported upstream:
http://tug.org/pipermail/tex-k/2017-August/002797.html

--- texk/dvipsk/color.c.orig	2016-11-25 18:08:46.000000000 +0000
+++ texk/dvipsk/color.c
@@ -37,7 +37,7 @@ static struct colorpage {
    struct colorpage *next;
    integer boploc; /* we use the bop loc as a page indicator */
    char *bg;
-   char colordat[2];
+   char colordat[];
 } *colorhash[COLORHASH];
 static char *cstack, *csp, *cend, *bg;
 /*
@@ -216,7 +216,7 @@ bopcolor(int outtops)
       }
    } else {
       p = (struct colorpage *)mymalloc((integer)
-                  (strlen(cstack) + sizeof(struct colorpage) + MAXCOLORLEN));
+                  (strlen(cstack) + sizeof(struct colorpage) + MAXCOLORLEN + 2));
       p->next = colorhash[h];
       p->boploc = pageloc;
       strcpy(p->colordat, cstack);
