$NetBSD: patch-flashrom.c,v 1.1 2014/03/06 15:46:39 joerg Exp $

--- flashrom.c.orig	2014-03-02 13:42:29.000000000 +0000
+++ flashrom.c
@@ -1738,7 +1738,7 @@ int selfcheck(void)
 	 * For 'flashchips' we check the first element to be non-null. In the
 	 * other cases there exist use cases where the first element can be
 	 * null. */
-	if (flashchips == NULL || flashchips[0].vendor == NULL) {
+	if (flashchips[0].vendor == NULL) {
 		msg_gerr("Flashchips table miscompilation!\n");
 		ret = 1;
 	}
@@ -1746,7 +1746,7 @@ int selfcheck(void)
 		if (selfcheck_eraseblocks(chip))
 			ret = 1;
 
-#if CONFIG_INTERNAL == 1
+#if 0 && CONFIG_INTERNAL == 1
 	if (chipset_enables == NULL) {
 		msg_gerr("Chipset enables table does not exist!\n");
 		ret = 1;
