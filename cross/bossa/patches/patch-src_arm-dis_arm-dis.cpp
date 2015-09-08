$NetBSD: patch-src_arm-dis_arm-dis.cpp,v 1.1 2015/09/08 18:52:13 joerg Exp $

--- src/arm-dis/arm-dis.cpp.orig	2015-09-03 11:58:25.000000000 +0000
+++ src/arm-dis/arm-dis.cpp
@@ -1961,7 +1961,7 @@ print_insn_coprocessor (bfd_vma pc,
 
 		    /* Is ``imm'' a negative number?  */
 		    if (imm & 0x40)
-		      imm |= (-1 << 7);
+		      imm |= -128;
 
 		    func (stream, "%d", imm);
 		  }
