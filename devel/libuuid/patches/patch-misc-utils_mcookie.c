$NetBSD: patch-misc-utils_mcookie.c,v 1.1 2021/07/25 04:00:34 dholland Exp $

Rename random_get_bytes to avoid symbol name conflict on Solaris.

--- misc-utils/mcookie.c~	2018-06-04 07:57:02.810445749 +0000
+++ misc-utils/mcookie.c
@@ -180,7 +180,7 @@ int main(int argc, char **argv)
 	randomness_from_files(&ctl);
 	free(ctl.files);
 
-	random_get_bytes(&buf, RAND_BYTES);
+	my_random_get_bytes(&buf, RAND_BYTES);
 	ul_MD5Update(&ctl.ctx, buf, RAND_BYTES);
 	if (ctl.verbose)
 		fprintf(stderr, P_("Got %d byte from %s\n",
