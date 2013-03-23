$NetBSD: patch-lib_kformula_creationstrategy.h,v 1.1 2013/03/23 10:15:26 joerg Exp $

--- lib/kformula/creationstrategy.h.orig	2013-02-28 15:33:21.000000000 +0000
+++ lib/kformula/creationstrategy.h
@@ -86,7 +86,7 @@ public:
  */
 class OrdinaryCreationStrategy : public ElementCreationStrategy {
 public:
-    virtual BasicElement* createElement( QString type, const QDomElement& element = 0 );
+    virtual BasicElement* createElement( QString type, const QDomElement& element);
 
     virtual TextElement* createTextElement( const QChar& ch, bool symbol=false );
     virtual EmptyElement* createEmptyElement();
