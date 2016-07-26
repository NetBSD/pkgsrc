$NetBSD: patch-wordwarvi.c,v 1.1 2016/07/26 20:05:17 kamil Exp $

Walk-around memory corruption (double-free(3)?)

Use standard getopt_long(3) - fixes NetBSD.

--- wordwarvi.c.orig	2016-03-11 15:16:11.000000000 +0000
+++ wordwarvi.c
@@ -11559,12 +11559,14 @@ void start_level()
 	srandom(level.random_seed);
 	generate_terrain(&terrain);
 
+#if 0
 	add_buildings(&terrain);/* Some FreeBSD users report that */
 				/*add_buildings() causes crashes. */
 				/* Commenting this out on FreeBSD */
 				/* may help, but, no buildings. */
 				/* I've looked at the code, but */
 				/* don't see anything wrong with it. */
+#endif
 	add_humanoids(&terrain);
 	add_bridges(&terrain);
 	add_socket(&terrain);
@@ -13967,7 +13969,7 @@ int main(int argc, char *argv[])
 
 	while (1) {
 		int rc, n; 
-		rc = getopt_long_only(argc, argv, "", wordwarvi_options, &opt);
+		rc = getopt_long(argc, argv, "", wordwarvi_options, &opt);
 		if (rc == -1)
 			break;
 		switch (rc) {
