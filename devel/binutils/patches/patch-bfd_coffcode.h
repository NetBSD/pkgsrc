$NetBSD: patch-bfd_coffcode.h,v 1.1 2022/12/11 16:43:11 fcambus Exp $

Fix for CVE-2022-38533: heap buffer overflow in strip (Binutils PR29482).

Upstream commit ef186fe54aa6d281a3ff8a9528417e5cc614c797.

--- bfd/coffcode.h.orig	2022-07-08 09:46:47.000000000 +0000
+++ bfd/coffcode.h
@@ -4284,10 +4284,13 @@ coff_set_section_contents (bfd * abfd,
 
 	rec = (bfd_byte *) location;
 	recend = rec + count;
-	while (rec < recend)
+	while (recend - rec >= 4)
 	  {
+	    size_t len = bfd_get_32 (abfd, rec);
+	    if (len == 0 || len > (size_t) (recend - rec) / 4)
+	      break;
+	    rec += len * 4;
 	    ++section->lma;
-	    rec += bfd_get_32 (abfd, rec) * 4;
 	  }
 
 	BFD_ASSERT (rec == recend);
