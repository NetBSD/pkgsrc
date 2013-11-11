$NetBSD: patch-umbrello_codeimport_kdevcppparser_preprocesslexer.cpp,v 1.1 2013/11/11 16:47:07 joerg Exp $

Patches from upstream.

--- umbrello/codeimport/kdevcppparser/preprocesslexer.cpp.orig	2013-06-28 18:06:03.000000000 +0000
+++ umbrello/codeimport/kdevcppparser/preprocesslexer.cpp
@@ -41,13 +41,11 @@
 
 #define PREPROCESSLEXER_DEBUG
 
-#ifdef Q_CC_MSVC
 template <class _Tp>
-struct _Identity : public std::unary_function<_Tp,_Tp> {
+struct identity : public std::unary_function<_Tp,_Tp> {
   _Tp& operator()(_Tp& __x) const { return __x; }
   const _Tp& operator()(const _Tp& __x) const { return __x; }
 };
-#endif
 
 template <class _Tp>
 struct tilde : public std::unary_function<_Tp, _Tp> {
@@ -593,7 +591,7 @@ void PreprocessLexer::dumpToFile()
     if (!d.exists())
         d.mkdir(tempPath);
 
-    QString fileName = tempPath + '/' + currentPosition().file.toString().replace(QRegExp("[/:mn]"), "-");
+    QString fileName = tempPath + '/' + currentPosition().file.replace(QRegExp("[/:mn]"), "-");
     QFile f(fileName);
     if (f.open(QIODevice::WriteOnly | QIODevice::Text)) {
         QTextStream out(&f);
@@ -839,7 +837,7 @@ int PreprocessLexer::macroPrimary()
         if (!l_hit)
             result = 0;
     } else {
-        boost::function < int (int) > l_op = _Identity<int>();
+        boost::function < int (int) > l_op = identity<int>();
         if (m_source.parse(ch_p('+')
                            | ch_p('-')[var(l_op) = std::negate<int>()]
                            | ch_p('!')[var(l_op) = std::logical_not<int>()]
