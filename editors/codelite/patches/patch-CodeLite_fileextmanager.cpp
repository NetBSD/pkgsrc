$NetBSD: patch-CodeLite_fileextmanager.cpp,v 1.1 2020/03/23 11:57:13 nia Exp $

Add NetBSD specific matchers

--- CodeLite/fileextmanager.cpp.orig	2020-03-07 01:58:26.515745479 +0200
+++ CodeLite/fileextmanager.cpp
@@ -171,13 +171,15 @@
 
         // Initialize regexes:
         m_matchers.push_back(Matcher("#[ \t]*![ \t]*/bin/bash", TypeScript));
-        m_matchers.push_back(Matcher("#[ \t]*![ \t]*/bin/bash", TypeScript));
+        m_matchers.push_back(Matcher("#[ \t]*![ \t]*/usr/pkg/bin/bash", TypeScript));
         m_matchers.push_back(Matcher("#[ \t]*![ \t]*/usr/bin/sh", TypeScript));
         m_matchers.push_back(Matcher("#[ \t]*![ \t]*/usr/bin/bash", TypeScript));
         m_matchers.push_back(Matcher("#[ \t]*![ \t]*/bin/python", TypePython));
         m_matchers.push_back(Matcher("#[ \t]*![ \t]*/usr/bin/python", TypePython));
+        m_matchers.push_back(Matcher("#[ \t]*![ \t]*/usr/pkg/bin/python[2-3][.][0-9]+", TypePython));
         m_matchers.push_back(Matcher("#[ \t]*![ \t]*/bin/node", TypeJS));
         m_matchers.push_back(Matcher("#[ \t]*![ \t]*/usr/bin/node", TypeJS));
+        m_matchers.push_back(Matcher("#[ \t]*![ \t]*/usr/pkg/bin/node", TypeJS));
         m_matchers.push_back(Matcher("#[ \t]*![ \t]*/bin/nodejs", TypeJS));
         m_matchers.push_back(Matcher("#[ \t]*![ \t]*/usr/bin/nodejs", TypeJS));
         m_matchers.push_back(Matcher("<?xml", TypeXml, false));
