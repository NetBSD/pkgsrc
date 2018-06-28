$NetBSD: patch-qemu-xen_hw_i386_ssdt_pcihp.dsl,v 1.1 2018/06/28 02:26:49 maya Exp $

Fix seabios build with newer iasl.

--- qemu-xen/hw/i386/ssdt-pcihp.dsl.orig	2016-07-27 17:50:05.000000000 +0000
+++ qemu-xen/hw/i386/ssdt-pcihp.dsl
@@ -15,7 +15,7 @@
 
 ACPI_EXTRACT_ALL_CODE ssdp_pcihp_aml
 
-DefinitionBlock ("ssdt-pcihp.aml", "SSDT", 0x01, "BXPC", "BXSSDTPCIHP", 0x1)
+DefinitionBlock ("ssdt-pcihp.aml", "SSDT", 0x01, "BXPC", "BXSSDTPC", 0x1)
 {
 
 /****************************************************************
