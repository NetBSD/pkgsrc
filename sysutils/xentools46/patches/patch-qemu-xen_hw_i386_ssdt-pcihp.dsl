$NetBSD: patch-qemu-xen_hw_i386_ssdt-pcihp.dsl,v 1.1.2.2 2018/07/05 08:45:27 bsiegert Exp $

Fix for newer iasl.
Length was previously truncated to 8 characters.

--- qemu-xen/hw/i386/ssdt-pcihp.dsl.orig	2017-06-21 15:43:09.000000000 +0000
+++ qemu-xen/hw/i386/ssdt-pcihp.dsl
@@ -15,7 +15,7 @@
 
 ACPI_EXTRACT_ALL_CODE ssdp_pcihp_aml
 
-DefinitionBlock ("ssdt-pcihp.aml", "SSDT", 0x01, "BXPC", "BXSSDTPCIHP", 0x1)
+DefinitionBlock ("ssdt-pcihp.aml", "SSDT", 0x01, "BXPC", "BXSSDTPC", 0x1)
 {
 
 /****************************************************************
