$NetBSD: patch-src_gboy__x86__64.S,v 1.1 2013/11/29 12:55:37 joerg Exp $

--- src/gboy_x86_64.S.orig	2013-11-27 23:28:07.000000000 +0000
+++ src/gboy_x86_64.S
@@ -1824,7 +1824,7 @@ op_sbc:
 	andq $F_ZERO, %rdx # mask in zero flag
 	andq $~F_ZERO, (%r10) # zero zero flag
 	orq %rdx, (%r10) # copy new zero flag
-	or $F_SUBTRACT, (%r10) # unset F_SUBTRACT
+	orl $F_SUBTRACT, (%r10) # unset F_SUBTRACT
 	movq %r11, %rdx
 	shlq $1, %rdx # move carry bit into position
 	andq $F_HCARRY, %rdx # mask in carry bit
@@ -3959,7 +3959,7 @@ op_jmp:
 	movq $addr_sp_ptrs, %rdi
 	movq %r13, %r11 # save
 	movq $regs_sets, %r10
-	movw %r13, PC(%r10)
+	movw %r13w, PC(%r10)
 	shrq $9, %r13 # get
 	andq $0x78, %r13 #  offset to pointer in addr_sp_ptrs
 	addq %r13, %rdi # point to address space
@@ -3987,7 +3987,7 @@ op_jmp_nz:
 	andq $0xffff, %r13 # mask in word
 	movq $addr_sp_ptrs, %rdi
 	movq %r13, %r11 # save
-	movw %r13, PC(%rbx)
+	movw %r13w, PC(%rbx)
 	shrq $9, %r13 # get
 	andq $0x78, %r13 #  offset to pointer in addr_sp_ptrs
 	addq %r13, %rdi # point to address space
@@ -4016,7 +4016,7 @@ op_jmp_z:
 	andq $0xffff, %r13 # mask in word
 	movq $addr_sp_ptrs, %rdi
 	movq %r13, %r11 # save
-	movw %r13, PC(%r10)
+	movw %r13w, PC(%r10)
 	shrq $9, %r13 # get
 	andq $0x78, %r13 #  offset to pointer in addr_sp_ptrs
 	addq %r13, %rdi # point to address space
@@ -4046,7 +4046,7 @@ op_jmp_c:
 	andq $0xffff, %r13 # mask in word
 	movq $addr_sp_ptrs, %rdi
 	movq %r13, %r11 # save
-	movw %r13, PC(%rbx)
+	movw %r13w, PC(%rbx)
 	shrq $9, %r13 # get
 	andq $0x78, %r13 #  offset to pointer in addr_sp_ptrs
 	addq %r13, %rdi # point to address space
@@ -4076,7 +4076,7 @@ op_jmp_nc:
 	andq $0xffff, %r13 # mask in word
 	movq $addr_sp_ptrs, %rdi
 	movq %r13, %r11 # save
-	movw %r13, PC(%rbx)
+	movw %r13w, PC(%rbx)
 	shrq $9, %r13 # get
 	andq $0x78, %r13 #  offset to pointer in addr_sp_ptrs
 	addq %r13, %rdi # point to address space
