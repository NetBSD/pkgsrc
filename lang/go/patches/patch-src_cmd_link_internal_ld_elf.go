$NetBSD: patch-src_cmd_link_internal_ld_elf.go,v 1.3 2018/03/04 12:54:06 bsiegert Exp $

--- src/cmd/link/internal/ld/elf.go.orig	2018-02-16 17:12:19.000000000 +0000
+++ src/cmd/link/internal/ld/elf.go
@@ -821,10 +821,12 @@ func elfwritenotehdr(out *OutBuf, str st
 
 // NetBSD Signature (as per sys/exec_elf.h)
 const (
-	ELF_NOTE_NETBSD_NAMESZ  = 7
-	ELF_NOTE_NETBSD_DESCSZ  = 4
-	ELF_NOTE_NETBSD_TAG     = 1
-	ELF_NOTE_NETBSD_VERSION = 599000000 /* NetBSD 5.99 */
+	ELF_NOTE_NETBSD_NAMESZ       = 7
+	ELF_NOTE_NETBSD_DESCSZ       = 4
+	ELF_NOTE_NETBSD_TAG          = 1
+	ELF_NOTE_NETBSD_VERSION      = 599000000 /* NetBSD 5.99 */
+	ELF_NOTE_NETBSD_MARCH_NAMESZ = 7
+	ELF_NOTE_NETBSD_MARCH_TAG    = 5
 )
 
 var ELF_NOTE_NETBSD_NAME = []byte("NetBSD\x00")
@@ -834,6 +836,23 @@ func elfnetbsdsig(sh *ElfShdr, startva u
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
 func elfwritenetbsdsig(out *OutBuf) int {
 	// Write Elf_Note header.
 	sh := elfwritenotehdr(out, ".note.netbsd.ident", ELF_NOTE_NETBSD_NAMESZ, ELF_NOTE_NETBSD_DESCSZ, ELF_NOTE_NETBSD_TAG)
@@ -850,6 +869,22 @@ func elfwritenetbsdsig(out *OutBuf) int
 	return int(sh.size)
 }
 
+func elfwritenetbsdarmsig(out *OutBuf) int {
+	mArch := elfnetbsdarmarch()
+	descsz := len(mArch)
+	sh := elfwritenotehdr(out, ".note.netbsd.march",
+		ELF_NOTE_NETBSD_MARCH_NAMESZ, uint32(descsz),
+		ELF_NOTE_NETBSD_MARCH_TAG)
+	if sh == nil {
+		return 0
+	}
+	out.Write(ELF_NOTE_NETBSD_NAME)
+	out.Write8(0)
+	out.Write(mArch)
+
+	return int(sh.size)
+}
+
 // OpenBSD Signature
 const (
 	ELF_NOTE_OPENBSD_NAMESZ  = 8
@@ -1452,6 +1487,9 @@ func (ctxt *Link) doelf() {
 	}
 	if ctxt.HeadType == objabi.Hnetbsd {
 		Addstring(shstrtab, ".note.netbsd.ident")
+		if ctxt.Arch.Family == sys.ARM {
+			Addstring(shstrtab, ".note.netbsd.march")
+		}
 	}
 	if ctxt.HeadType == objabi.Hopenbsd {
 		Addstring(shstrtab, ".note.openbsd.ident")
@@ -1890,6 +1928,15 @@ func Asmbelf(ctxt *Link, symo int64) {
 		pnote.flags = PF_R
 		phsh(pnote, sh)
 	}
+	if ctxt.HeadType == objabi.Hnetbsd && ctxt.Arch.Family == sys.ARM {
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
@@ -2232,6 +2279,9 @@ elfobj:
 	if ctxt.LinkMode != LinkExternal {
 		if ctxt.HeadType == objabi.Hnetbsd {
 			a += int64(elfwritenetbsdsig(ctxt.Out))
+			if ctxt.Arch.Family == sys.ARM {
+				a += int64(elfwritenetbsdarmsig(ctxt.Out))
+			}
 		}
 		if ctxt.HeadType == objabi.Hopenbsd {
 			a += int64(elfwriteopenbsdsig(ctxt.Out))
