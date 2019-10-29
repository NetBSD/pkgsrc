$NetBSD: patch-src_dhcpcd-qt_dhcpcd-preferences.cpp,v 1.1 2019/10/29 12:39:13 kamil Exp $

Port to Qt5.

--- src/dhcpcd-qt/dhcpcd-preferences.cpp.orig	2015-01-07 09:18:28.000000000 +0000
+++ src/dhcpcd-qt/dhcpcd-preferences.cpp
@@ -182,10 +182,10 @@ void DhcpcdPreferences::listBlocks(const
 	blocks->disconnect(this);
 
 	free(eWhat);
-	eWhat = strdup(txt.toLower().toAscii());
+	eWhat = strdup(txt.toLower().toLatin1());
 
 	list = dhcpcd_config_blocks(parent->getConnection(),
-	    txt.toLower().toAscii());
+	    txt.toLower().toLatin1());
 
 	if (txt == "interface") {
 		char **ifaces, **i;
@@ -294,7 +294,7 @@ const char *DhcpcdPreferences::getString
 {
 	if (le->text().isEmpty())
 		return NULL;
-	return le->text().trimmed().toAscii();
+	return le->text().trimmed().toLatin1();
 }
 
 bool DhcpcdPreferences::setOption(const char *opt, const char *val, bool *ret)
@@ -405,7 +405,7 @@ void DhcpcdPreferences::showBlock(const 
 	if (txt.isEmpty())
 		eBlock = NULL;
 	else
-		eBlock = strdup(txt.toAscii());
+		eBlock = strdup(txt.toLatin1());
 
 	dhcpcd_config_free(config);
 	iface = NULL;
