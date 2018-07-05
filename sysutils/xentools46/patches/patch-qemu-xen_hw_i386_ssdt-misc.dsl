$NetBSD: patch-qemu-xen_hw_i386_ssdt-misc.dsl,v 1.1.2.2 2018/07/05 08:45:27 bsiegert Exp $

Fix for newer iasl.
Length was previously truncated to 8 characters.

--- qemu-xen/hw/i386/ssdt-misc.dsl.orig	2017-06-21 15:43:09.000000000 +0000
+++ qemu-xen/hw/i386/ssdt-misc.dsl
@@ -16,7 +16,7 @@
 
 ACPI_EXTRACT_ALL_CODE ssdp_misc_aml
 
-DefinitionBlock ("ssdt-misc.aml", "SSDT", 0x01, "BXPC", "BXSSDTSUSP", 0x1)
+DefinitionBlock ("ssdt-misc.aml", "SSDT", 0x01, "BXPC", "BXSSDTSU", 0x1)
 {
 
 /****************************************************************
