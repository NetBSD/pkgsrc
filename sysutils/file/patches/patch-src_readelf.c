$NetBSD: patch-src_readelf.c,v 1.1 2018/06/30 09:27:03 bsiegert Exp $

apply https://github.com/file/file/commit/a642587a9c9e2dd7feacdf513c3643ce26ad3c22
against https://nvd.nist.gov/vuln/detail/CVE-2018-10360

    ...
    The do_core_note function in readelf.c in libmagic.a in file
    5.33 allows remote attackers to cause a denial of service
    (out-of-bounds read and application crash) via a crafted ELF
    file.
    ...

--- src/readelf.c.orig	2017-08-27 07:55:02.000000000 +0000
+++ src/readelf.c
@@ -824,7 +824,8 @@ do_core_note(struct magic_set *ms, unsig
 
 				cname = (unsigned char *)
 				    &nbuf[doff + prpsoffsets(i)];
-				for (cp = cname; *cp && isprint(*cp); cp++)
+				for (cp = cname; cp < nbuf + size && *cp
+				    && isprint(*cp); cp++)
 					continue;
 				/*
 				 * Linux apparently appends a space at the end
