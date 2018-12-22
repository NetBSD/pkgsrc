$NetBSD: patch-src_Qt_qtel6.cpp,v 1.1 2018/12/22 16:06:30 tsutsui Exp $

- Fix URL for "online help" menu. (already fixed in upstream)

--- src/Qt/qtel6.cpp.orig	2018-12-15 09:06:43.000000000 +0000
+++ src/Qt/qtel6.cpp
@@ -143,7 +143,7 @@ void EL6::ExecMenu( int id )
 		QDesktopServices::openUrl(QUrl::fromLocalFile(QString("file://") + OSD_GetModulePath() + "/README.html"));
 		break;
 #else
-		QDesktopServices::openUrl(QUrl("https://github.com/eighttails/PC6001VX/blob/master/README.mkd"));
+		QDesktopServices::openUrl(QUrl("https://github.com/eighttails/PC6001VX/blob/master/README.adoc"));
 		break;
 #endif
 	case ID_VERSION:		OSD_VersionDialog( graph->GetWindowHandle(), cfg->GetModel() );	break;	// バージョン情報
