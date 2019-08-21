$NetBSD: patch-src_amd_common_ac__debug.c,v 1.1 2019/08/21 13:35:28 nia Exp $

#if'out some debug code on SunOS. There is no open_memstream(3)

--- src/amd/common/ac_debug.c.orig	2019-01-17 11:26:22.000000000 +0000
+++ src/amd/common/ac_debug.c
@@ -571,10 +571,12 @@ void ac_parse_ib_chunk(FILE *f, uint32_t
 
 	char *out;
 	size_t outsize;
+#if defined(HAVE_OPEN_MEMSTREAM)
 	FILE *memf = open_memstream(&out, &outsize);
 	ib.f = memf;
 	ac_do_parse_ib(memf, &ib);
 	fclose(memf);
+#endif
 
 	if (out) {
 		format_ib_output(f, out);
