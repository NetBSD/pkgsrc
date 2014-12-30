$NetBSD: patch-util_Util.h,v 1.1 2014/12/30 08:50:55 plunky Exp $

zyGrib normally runs in the build directory, but we install data files
to PREFIX/share/zyGrib, so fix the path part there.

--- util/Util.h.orig	2014-12-27 20:51:22.000000000 +0000
+++ util/Util.h
@@ -70,16 +70,16 @@ class Util : public QObject
 	static QString getOpenFileName (QWidget *parent, const QString &caption, 
 							const QString &dir, const QString &filter=QString());
 		
-	static QString pathData ()   {return "./";};
-	static QString pathColors () {return pathData()+"data/colors/";}
-	static QString pathConfig () {return pathData()+"data/config/";}
-	static QString pathFonts ()  {return pathData()+"data/fonts/";}
-	static QString pathGis ()    {return pathData()+"data/gis/";}
-	static QString pathGshhs ()  {return pathData()+"data/maps/gshhs/";}
-	static QString pathStuff ()  {return pathData()+"data/stuff/";}
+	static QString pathData ()   {return "@PREFIX@/share/zyGrib/";};
+	static QString pathColors () {return pathData()+"colors/";}
+	static QString pathConfig () {return pathData()+"config/";}
+	static QString pathFonts ()  {return pathData()+"fonts/";}
+	static QString pathGis ()    {return pathData()+"gis/";}
+	static QString pathGshhs ()  {return pathData()+"maps/gshhs/";}
+	static QString pathStuff ()  {return pathData()+"stuff/";}
 	
-	static QString pathImg (const char *fname) {return pathData()+"data/img/"+fname;}
-	static QString pathTr  (QString lang)   {return pathData()+"data/tr/zyGrib_"+lang;}
+	static QString pathImg (const char *fname) {return pathData()+"img/"+fname;}
+	static QString pathTr  (QString lang)   {return pathData()+"tr/zyGrib_"+lang;}
 	static QString getServerName ();
 
     static void     setSetting (const QString &key, const QVariant &value);
