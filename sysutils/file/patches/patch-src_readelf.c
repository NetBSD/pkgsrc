$NetBSD: patch-src_readelf.c,v 1.2 2019/03/16 09:02:41 bsiegert Exp $

apply https://github.com/file/file/commit/a642587a9c9e2dd7feacdf513c3643ce26ad3c22
against https://nvd.nist.gov/vuln/detail/CVE-2018-10360

    ...
    The do_core_note function in readelf.c in libmagic.a in file
    5.33 allows remote attackers to cause a denial of service
    (out-of-bounds read and application crash) via a crafted ELF
    file.
    ...

Avoid OOB read (found by ASAN reported by F. Alonso) (CVE-2019-8906)

https://github.com/file/file/commit/2858eaf99f6cc5aae129bcbf1e24ad160240185f

fix PR/62: spinpx: limit size of file_printable.  (CVE-2019-8904)

https://bugs.astron.com/view.php?id=62
https://github.com/file/file/commit/d65781527c8134a1202b2649695d48d5701ac60b

--- src/readelf.c.orig	2017-08-27 07:55:02.000000000 +0000
+++ src/readelf.c
@@ -720,12 +720,12 @@ do_core_note(struct magic_set *ms, unsig
 			char sbuf[512];
 			struct NetBSD_elfcore_procinfo pi;
 			memset(&pi, 0, sizeof(pi));
-			memcpy(&pi, nbuf + doff, descsz);
+			memcpy(&pi, nbuf + doff, MIN(descsz, sizeof(pi)));
 
 			if (file_printf(ms, ", from '%.31s', pid=%u, uid=%u, "
 			    "gid=%u, nlwps=%u, lwp=%u (signal %u/code %u)",
 			    file_printable(sbuf, sizeof(sbuf),
-			    CAST(char *, pi.cpi_name)),
+			    RCAST(char *, pi.cpi_name), sizeof(pi.cpi_name)),
 			    elf_getu32(swap, pi.cpi_pid),
 			    elf_getu32(swap, pi.cpi_euid),
 			    elf_getu32(swap, pi.cpi_egid),
@@ -824,7 +824,8 @@ do_core_note(struct magic_set *ms, unsig
 
 				cname = (unsigned char *)
 				    &nbuf[doff + prpsoffsets(i)];
-				for (cp = cname; *cp && isprint(*cp); cp++)
+				for (cp = cname; cp < nbuf + size && *cp
+				    && isprint(*cp); cp++)
 					continue;
 				/*
 				 * Linux apparently appends a space at the end
@@ -1564,7 +1565,8 @@ dophn_exec(struct magic_set *ms, int cla
 		return -1;
 	if (interp[0])
 		if (file_printf(ms, ", interpreter %s",
-		    file_printable(ibuf, sizeof(ibuf), interp)) == -1)
+		    file_printable(ibuf, sizeof(ibuf), interp, sizeof(interp)))
+			== -1)
 			return -1;
 	return 0;
 }
