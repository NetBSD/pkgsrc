$NetBSD: patch-umbrello_codeimport_kdevcppparser_position.h,v 1.1 2013/11/11 16:47:07 joerg Exp $

Patches from upstream.

--- umbrello/codeimport/kdevcppparser/position.h.orig	2013-06-28 18:06:03.000000000 +0000
+++ umbrello/codeimport/kdevcppparser/position.h
@@ -20,22 +20,6 @@
 #ifndef POSITION_H
 #define POSITION_H
 
-#ifdef _MSC_VER //Q_CC_MSVC isn't defined here
-/*
-workaround for the following msvc error 
-...\Microsoft Visual Studio 8\VC\INCLUDE\xstring(2044) : error C2620: 
-    member 'std::basic_string<_Elem>::_Bxty::_Buf ' of union 'std::basic_string<_Elem>::_Bxty' 
-    has user-defined constructor or non-trivial default constructor with [  _Elem=QChar]
-...\Microsoft Visual Studio 8\VC\INCLUDE\xstring(2046) : see reference to class 
-    template instantiation 'std::basic_string<_Elem>::_Bxty' being compiled with [  _Elem=QChar]
-..\umbrello\umbrello\codeimport\kdevcppparser\position.h(49) : see reference to class 
-    template instantiation 'std::basic_string<_Elem>' being compiled with [  _Elem=QChar]
-*/
-#define union struct 
-#include <xstring>
-#undef union 
-#endif
-
 #include <limits.h>
 #include <boost/version.hpp>
 #include <boost/spirit/include/classic.hpp>
@@ -43,34 +27,7 @@ workaround for the following msvc error 
 #include <QChar>
 #include <QDebug>
 
-typedef std::basic_string<QChar> PositionFilenameType;
-
-class PositionFilename : public PositionFilenameType
-{
-public:
-    PositionFilename()
-    {
-    }
-
-    explicit PositionFilename(const QString &p) : PositionFilenameType(p.data())
-    {
-    }
-
-    QString toString() const
-    {
-        QString result;
-        for(unsigned int i = 0; i < size(); i++)
-            result.append(at(i));
-        return result;
-    }
-};
-
-inline QDebug operator<<(QDebug out, const PositionFilename &p)
-{
-    out << p.toString();
-    return out;
-}
-
+typedef QString PositionFilename;
 typedef boost::spirit::classic::file_position_base<PositionFilename> PositionType;
 
 class Position : public PositionType
