$NetBSD: patch-.._.._ipxe_src_arch_i386_include_librm.h,v 1.1.2.2 2013/04/24 21:11:06 tron Exp $

--- ../../ipxe/src/arch/i386/include/librm.h.orig	2010-02-02 16:12:44.000000000 +0000
+++ ../../ipxe/src/arch/i386/include/librm.h
@@ -122,8 +122,9 @@ extern char *text16;
 	_data16_ ## variable __asm__ ( #variable )
 
 #define __bss16_array( variable, array )				\
-	__attribute__ (( section ( ".bss16" ) ))			\
-	_data16_ ## variable array __asm__ ( #variable )
+	_data16_ ## variable array \
+	__asm__ ( #variable ) \
+	__attribute__ (( section ( ".bss16" ) ))
 
 #define __text16( variable )						\
 	__attribute__ (( section ( ".text16.data" ) ))			\
