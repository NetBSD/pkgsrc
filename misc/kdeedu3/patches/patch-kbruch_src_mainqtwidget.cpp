$NetBSD: patch-kbruch_src_mainqtwidget.cpp,v 1.1 2014/07/14 09:35:47 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kbruch/src/mainqtwidget.cpp.orig	2005-09-10 08:18:00.000000000 +0000
+++ kbruch/src/mainqtwidget.cpp
@@ -131,7 +131,7 @@ void MainQtWidget::readOptions()
 	m_maxMainDenominator = SettingsClass::max_main_denominator();
 
 	/* make sure that we can load config files with corrupted values */
-	if (m_mulDiv == true && pow(2, m_nrRatios) > m_maxMainDenominator)
+	if (m_mulDiv == true && pow((float)2, (float)m_nrRatios) > m_maxMainDenominator)
 	{
 		m_nrRatios = 2;
 		m_maxMainDenominator = 10;
