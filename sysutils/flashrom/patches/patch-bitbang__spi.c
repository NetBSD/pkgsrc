$NetBSD: patch-bitbang__spi.c,v 1.1 2012/11/23 12:08:04 joerg Exp $

--- bitbang_spi.c.orig	2012-11-22 21:16:09.000000000 +0000
+++ bitbang_spi.c
@@ -26,33 +26,33 @@
 #include "spi.h"
 
 /* Note that CS# is active low, so val=0 means the chip is active. */
-static void bitbang_spi_set_cs(const const struct bitbang_spi_master *master, int val)
+static void bitbang_spi_set_cs(const struct bitbang_spi_master *master, int val)
 {
 	master->set_cs(val);
 }
 
-static void bitbang_spi_set_sck(const const struct bitbang_spi_master *master, int val)
+static void bitbang_spi_set_sck(const struct bitbang_spi_master *master, int val)
 {
 	master->set_sck(val);
 }
 
-static void bitbang_spi_set_mosi(const const struct bitbang_spi_master *master, int val)
+static void bitbang_spi_set_mosi(const struct bitbang_spi_master *master, int val)
 {
 	master->set_mosi(val);
 }
 
-static int bitbang_spi_get_miso(const const struct bitbang_spi_master *master)
+static int bitbang_spi_get_miso(const struct bitbang_spi_master *master)
 {
 	return master->get_miso();
 }
 
-static void bitbang_spi_request_bus(const const struct bitbang_spi_master *master)
+static void bitbang_spi_request_bus(const struct bitbang_spi_master *master)
 {
 	if (master->request_bus)
 		master->request_bus();
 }
 
-static void bitbang_spi_release_bus(const const struct bitbang_spi_master *master)
+static void bitbang_spi_release_bus(const struct bitbang_spi_master *master)
 {
 	if (master->release_bus)
 		master->release_bus();
