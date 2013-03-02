$NetBSD: patch-src_bin_geomutil_ucd_anytoucd.c,v 1.1 2013/03/02 18:09:30 joerg Exp $

--- src/bin/geomutil/ucd/anytoucd.c.orig	2013-03-01 21:50:46.000000000 +0000
+++ src/bin/geomutil/ucd/anytoucd.c
@@ -402,7 +402,7 @@ main(argc, argv)	int argc; char **argv;
 	else if (n==3)  fprintf(fp,"tri ");
 	else if (n==4) fprintf(fp, "quad ");
 	/* else signal error */
-	else return;
+	else return 1;
         for(vp = p->v; --n >= 0; vp++)
                 fprintf(fp, "%d ", (*vp) - thispl->vl + 1);
 	fprintf(fp,"\n");
