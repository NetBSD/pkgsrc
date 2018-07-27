$NetBSD: patch-src_gui-qt_showtextfile.cpp,v 1.1 2018/07/27 07:39:12 schmonz Exp $

Use X11 on Darwin, like everywhere else.

--- src/gui-qt/showtextfile.cpp.orig	2018-07-19 17:57:22.000000000 +0000
+++ src/gui-qt/showtextfile.cpp
@@ -30,6 +30,8 @@ along with Highlight.  If not, see <http
 #include <QFile>
 #include <QDir>
 
+#undef Q_OS_OSX
+
 ShowTextFile::ShowTextFile(QWidget *parent) :
     QDialog(parent),
     m_ui(new Ui::ShowTextFile)
