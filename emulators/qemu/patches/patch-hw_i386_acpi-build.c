$NetBSD: patch-hw_i386_acpi-build.c,v 1.1 2021/06/16 09:39:17 jperkin Exp $

Avoid "sun" define.

--- hw/i386/acpi-build.c.orig	2021-04-29 17:18:58.000000000 +0000
+++ hw/i386/acpi-build.c
@@ -534,7 +534,7 @@ Aml *aml_pci_device_dsm(void)
     Aml *bnum = aml_arg(4);
     Aml *func = aml_arg(2);
     Aml *rev = aml_arg(1);
-    Aml *sun = aml_arg(5);
+    Aml *qsun = aml_arg(5);
 
     method = aml_method("PDSM", 6, AML_SERIALIZED);
 
@@ -545,7 +545,7 @@ Aml *aml_pci_device_dsm(void)
     UUID = aml_touuid("E5C937D0-3553-4D7A-9117-EA4D19C3434D");
     ifctx = aml_if(aml_equal(aml_arg(0), UUID));
     {
-        aml_append(ifctx, aml_store(aml_call2("AIDX", bnum, sun), acpi_index));
+        aml_append(ifctx, aml_store(aml_call2("AIDX", bnum, qsun), acpi_index));
         ifctx1 = aml_if(aml_equal(func, zero));
         {
             uint8_t byte_list[1];
