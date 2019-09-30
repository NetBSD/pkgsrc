$NetBSD: patch-lib_accelerated_x86_elf_aesni-x86.s,v 1.1 2019/09/30 09:51:16 maya Exp $


Avoid text relocations.

commit 56b333df895475b202780add2e873c7cf5ade0d3
Author: Andreas Metzler <ametzler@debian.org>
Date:   Sat Sep 28 14:28:12 2019 +0200

    Regenerate asm files with -fPIC
    
    CRYPTOGAMS' perl-scripts can produce different output if -fPIC is passed
    as option. Set -fPIC for the same files as openssl does.
    
    Closes #818

--- lib/accelerated/x86/elf/aesni-x86.s.orig	2019-06-28 19:06:07.000000000 +0000
+++ lib/accelerated/x86/elf/aesni-x86.s
@@ -2892,7 +2892,7 @@ _aesni_set_encrypt_key:
 .L112pic:
 	popl	%ebx
 	leal	.Lkey_const-.L112pic(%ebx),%ebx
-	leal	_gnutls_x86_cpuid_s,%ebp
+	leal	_gnutls_x86_cpuid_s-.Lkey_const(%ebx),%ebp
 	movups	(%eax),%xmm0
 	xorps	%xmm4,%xmm4
 	movl	4(%ebp),%ebp
