$NetBSD: patch-qemu-xen_hw_i386_ssdt_misc.dsl,v 1.1 2018/06/28 02:26:49 maya Exp $

Fix seabios build with newer iasl.
Length was previously truncated to 8 characters.

--- qemu-xen/hw/i386/ssdt-misc.dsl.orig	2016-07-27 17:50:05.000000000 +0000
+++ qemu-xen/hw/i386/ssdt-misc.dsl
@@ -15,7 +15,7 @@
 
 ACPI_EXTRACT_ALL_CODE ssdp_misc_aml
 
-DefinitionBlock ("ssdt-misc.aml", "SSDT", 0x01, "BXPC", "BXSSDTSUSP", 0x1)
+DefinitionBlock ("ssdt-misc.aml", "SSDT", 0x01, "BXPC", "BXSSDTSU", 0x1)
 {
 
 /****************************************************************
