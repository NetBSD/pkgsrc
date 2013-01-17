$NetBSD: patch-src_fetch_fetchmanager.h,v 1.1 2013/01/17 15:58:01 joerg Exp $

--- src/fetch/fetchmanager.h.orig	2013-01-16 12:48:51.000000000 +0000
+++ src/fetch/fetchmanager.h
@@ -65,6 +65,8 @@ Q_OBJECT
   typedef QString (*FETCHER_ICON_FN)(void);
   typedef StringHash (*FETCHER_OPTIONALFIELDS_FN)(void);
   typedef ConfigWidget* (*FETCHER_CONFIGWIDGET_FN)(QWidget*);
+
+public:
   struct FetcherFunction  {
     FETCHER_CREATE_FN create;
     FETCHER_NAME_FN name;
