$NetBSD: patch-src_cmd_link_internal_ld_elf.go,v 1.1 2018/07/08 17:59:07 bsiegert Exp $

--- src/cmd/link/internal/ld/elf.go.orig	2017-10-25 14:30:21.000000000 -0400
+++ src/cmd/link/internal/ld/elf.go	2018-01-20 11:49:02.046813855 -0500
@@ -1263,6 +1263,8 @@
 	ELF_NOTE_NETBSD_DESCSZ  = 4
 	ELF_NOTE_NETBSD_TAG     = 1
 	ELF_NOTE_NETBSD_VERSION = 599000000 /* NetBSD 5.99 */
+	ELF_NOTE_NETBSD_MARCH_NAMESZ = 7
+	ELF_NOTE_NETBSD_MARCH_TAG    = 5
 )
 
 var ELF_NOTE_NETBSD_NAME = []byte("NetBSD\x00")
@@ -1272,6 +1274,23 @@
 	return elfnote(sh, startva, resoff, n, true)
 }
 
+func elfnetbsdarmarch() []byte {
+	switch objabi.GOARM {
+	case 6:
+		return []byte("earmv6hf\x00")
+	case 7:
+		return []byte("earmv7hf\x00")
+	default:
+		return []byte("earm\x00")
+	}
+}
+
+func elfnetbsdarmsig(sh *ElfShdr, startva uint64, resoff uint64) int {
+	descsz := len(elfnetbsdarmarch())
+	n := int(Rnd(ELF_NOTE_NETBSD_MARCH_NAMESZ, 4) + Rnd(int64(descsz), 4))
+	return elfnote(sh, startva, resoff, n, true)
+}
+
 func elfwritenetbsdsig() int {
 	// Write Elf_Note header.
 	sh := elfwritenotehdr(".note.netbsd.ident", ELF_NOTE_NETBSD_NAMESZ, ELF_NOTE_NETBSD_DESCSZ, ELF_NOTE_NETBSD_TAG)
@@ -1285,7 +1304,20 @@
 	Cput(0)
 
 	Thearch.Lput(ELF_NOTE_NETBSD_VERSION)
-
+	if SysArch.Family == sys.ARM {
+		mArch := elfnetbsdarmarch()
+		descsz := len(mArch)
+		sh2 := elfwritenotehdr(".note.netbsd.march",
+			ELF_NOTE_NETBSD_MARCH_NAMESZ, uint32(descsz),
+			ELF_NOTE_NETBSD_MARCH_TAG)
+		if sh2 == nil {
+			return 0
+		}
+		Cwrite(ELF_NOTE_NETBSD_NAME)
+		Cput(0)
+		Cwrite(mArch)
+		return int(sh.size) + int(sh2.size)
+	}
 	return int(sh.size)
 }
 
@@ -1902,6 +1934,9 @@
 	}
 	if Headtype == objabi.Hnetbsd {
 		Addstring(shstrtab, ".note.netbsd.ident")
+		if SysArch.Family == sys.ARM {
+			Addstring(shstrtab, ".note.netbsd.march")
+		}
 	}
 	if Headtype == objabi.Hopenbsd {
 		Addstring(shstrtab, ".note.openbsd.ident")
@@ -2340,6 +2375,15 @@
 		pnote.flags = PF_R
 		phsh(pnote, sh)
 	}
+	if Headtype == objabi.Hnetbsd && SysArch.Family == sys.ARM {
+		var sh *ElfShdr
+		sh = elfshname(".note.netbsd.march")
+		resoff -= int64(elfnetbsdarmsig(sh, uint64(startva), uint64(resoff)))
+		pnote = newElfPhdr()
+		pnote.type_ = PT_NOTE
+		pnote.flags = PF_R
+		phsh(pnote, sh)
+	}
 
 	if len(buildinfo) > 0 {
 		sh := elfshname(".note.gnu.build-id")
