$NetBSD: patch-sgb2alt.c,v 1.1 2012/12/25 21:05:20 joerg Exp $

--- sgb2alt.c.orig	2012-12-25 18:50:46.000000000 +0000
+++ sgb2alt.c
@@ -36,14 +36,14 @@ main(argc,argv)
 
     if (argc != 3) {
 	    printf("sgb2old <sgfile> <altfile>\n\n");
-	    return;
+	    return 1;
     }
     fout = fopen(argv[2],"w");
 
     g = restore_graph(argv[1]);
 		if (g == NULL) {
       printf("%s does not contain a correct SGB graph\n",argv[1]);
-			return;
+			return 1;
 		}
 			
     fprintf(fout,"GRAPH (#nodes #edges id uu vv ww xx yy zz):\n");
