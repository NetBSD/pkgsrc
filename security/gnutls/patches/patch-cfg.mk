$NetBSD: patch-cfg.mk,v 1.1 2019/09/30 09:51:16 maya Exp $

Avoid text relocations.

commit 56b333df895475b202780add2e873c7cf5ade0d3
Author: Andreas Metzler <ametzler@debian.org>
Date:   Sat Sep 28 14:28:12 2019 +0200

    Regenerate asm files with -fPIC
    
    CRYPTOGAMS' perl-scripts can produce different output if -fPIC is passed
    as option. Set -fPIC for the same files as openssl does.
    
    Closes #818

--- cfg.mk.orig	2019-06-28 19:06:07.000000000 +0000
+++ cfg.mk
@@ -143,6 +143,12 @@ ASM_SOURCES_XXX := \
 	lib/accelerated/x86/XXX/aes-ssse3-x86.s \
 	lib/accelerated/x86/XXX/aes-ssse3-x86_64.s
 
+# CRYPTOGAMS' perl-scripts can produce different output if -fPIC
+# is passed as option. List the files that seem to need it:
+PL_NEEDS_FPIC := aesni-x86.pl aes-ssse3-x86.pl e_padlock-x86.pl \
+	ghash-x86.pl sha1-ssse3-x86.pl sha256-ssse3-x86.pl \
+	sha512-ssse3-x86.pl
+
 ASM_SOURCES_ELF := $(subst XXX,elf,$(ASM_SOURCES_XXX))
 ASM_SOURCES_COFF := $(subst XXX,coff,$(ASM_SOURCES_XXX))
 ASM_SOURCES_MACOSX := $(subst XXX,macosx,$(ASM_SOURCES_XXX))
@@ -193,33 +199,43 @@ lib/accelerated/x86/files.mk: $(ASM_SOUR
 
 # Appro's code
 lib/accelerated/x86/elf/%.s: devel/perlasm/%.pl .submodule.stamp 
-	CC=gcc perl $< elf $@.tmp
+	CC=gcc perl $< elf \
+		$(if $(findstring $(<F),$(PL_NEEDS_FPIC)),-fPIC) \
+		$@.tmp
 	cat $<.license $@.tmp > $@ && rm -f $@.tmp
 	echo "" >> $@
 	echo ".section .note.GNU-stack,\"\",%progbits" >> $@
 	sed -i 's/OPENSSL_ia32cap_P/_gnutls_x86_cpuid_s/g' $@
 
 lib/accelerated/x86/coff/%-x86.s: devel/perlasm/%-x86.pl .submodule.stamp 
-	CC=gcc perl $< coff $@.tmp
+	CC=gcc perl $< coff \
+		$(if $(findstring $(<F),$(PL_NEEDS_FPIC)),-fPIC) \
+		$@.tmp
 	cat $<.license $@.tmp > $@ && rm -f $@.tmp
 	echo "" >> $@
 	sed -i 's/OPENSSL_ia32cap_P/_gnutls_x86_cpuid_s/g' $@
 
 lib/accelerated/x86/coff/%-x86_64.s: devel/perlasm/%-x86_64.pl .submodule.stamp 
-	CC=gcc perl $< mingw64 $@.tmp
+	CC=gcc perl $< mingw64 \
+		$(if $(findstring $(<F),$(PL_NEEDS_FPIC)),-fPIC) \
+		$@.tmp
 	cat $<.license $@.tmp > $@ && rm -f $@.tmp
 	echo "" >> $@
 	sed -i 's/OPENSSL_ia32cap_P/_gnutls_x86_cpuid_s/g' $@
 
 lib/accelerated/x86/macosx/%.s: devel/perlasm/%.pl .submodule.stamp 
-	CC=gcc perl $< macosx $@.tmp
+	CC=gcc perl $< macosx \
+		$(if $(findstring $(<F),$(PL_NEEDS_FPIC)),-fPIC) \
+		$@.tmp
 	cat $<.license $@.tmp > $@ && rm -f $@.tmp
 	echo "" >> $@
 	sed -i 's/OPENSSL_ia32cap_P/_gnutls_x86_cpuid_s/g' $@
 
 lib/accelerated/aarch64/elf/%.s: devel/perlasm/%.pl .submodule.stamp 
 	rm -f $@tmp
-	CC=aarch64-linux-gnu-gcc perl $< linux64 $@.tmp
+	CC=aarch64-linux-gnu-gcc perl $< linux64 \
+		$(if $(findstring $(<F),$(PL_NEEDS_FPIC)),-fPIC) \
+		$@.tmp
 	cat $@.tmp | /usr/bin/perl -ne '/^#(line)?\s*[0-9]+/ or print' > $@.tmp.S
 	echo "" >> $@.tmp.S
 	sed -i 's/OPENSSL_armcap_P/_gnutls_arm_cpuid_s/g' $@.tmp.S
@@ -231,7 +247,9 @@ lib/accelerated/aarch64/elf/%.s: devel/p
 
 lib/accelerated/aarch64/macosx/%.s: devel/perlasm/%.pl .submodule.stamp
 	rm -f $@tmp
-	CC=aarch64-linux-gnu-gcc perl $< ios64 $@.tmp
+	CC=aarch64-linux-gnu-gcc perl $< ios64 \
+		$(if $(findstring $(<F),$(PL_NEEDS_FPIC)),-fPIC) \
+		$@.tmp
 	cat $@.tmp | /usr/bin/perl -ne '/^#(line)?\s*[0-9]+/ or print' > $@.tmp.S
 	echo "" >> $@.tmp.S
 	sed -i 's/OPENSSL_armcap_P/_gnutls_arm_cpuid_s/g' $@.tmp.S
