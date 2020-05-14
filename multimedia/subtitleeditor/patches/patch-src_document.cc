$NetBSD: patch-src_document.cc,v 1.1 2020/05/14 19:30:42 joerg Exp $

--- src/document.cc.orig	2020-05-13 22:31:40.710310072 +0000
+++ src/document.cc
@@ -78,7 +78,7 @@ Document::Document()
 /*
  * Constructor by copy
  */
-Document::Document(Document &src, bool copy_subtitles = true )
+Document::Document(Document &src, bool copy_subtitles)
 :CommandSystem(*this), m_subtitles(*this), m_styles(*this), m_subtitleView(NULL)
 {
 	m_timing_mode = src.m_timing_mode;
