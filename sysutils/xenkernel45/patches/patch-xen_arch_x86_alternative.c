$NetBSD: patch-xen_arch_x86_alternative.c,v 1.1 2017/05/07 21:21:01 joerg Exp $

--- xen/arch/x86/alternative.c.orig	2016-09-20 05:59:24.000000000 +0000
+++ xen/arch/x86/alternative.c
@@ -39,7 +39,7 @@ static const unsigned char k8nops[] __in
     K8_NOP7,
     K8_NOP8
 };
-static const unsigned char * const k8_nops[ASM_NOP_MAX+1] = {
+static const unsigned char * const k8_nops[ASM_NOP_MAX+1] __initconstrel = {
     NULL,
     k8nops,
     k8nops + 1,
@@ -63,7 +63,7 @@ static const unsigned char p6nops[] __in
     P6_NOP7,
     P6_NOP8
 };
-static const unsigned char * const p6_nops[ASM_NOP_MAX+1] = {
+static const unsigned char * const p6_nops[ASM_NOP_MAX+1] __initconstrel = {
     NULL,
     p6nops,
     p6nops + 1,
