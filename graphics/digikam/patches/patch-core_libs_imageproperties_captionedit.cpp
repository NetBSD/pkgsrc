$NetBSD: patch-core_libs_imageproperties_captionedit.cpp,v 1.1 2014/11/15 21:15:18 markd Exp $

commit f6945f23e0ed1e11f26e2c7e62b02baa8cfa640e
Author: Pino Toscano <pino@kde.org>
Date:   Tue Oct 14 22:26:19 2014 +0200

    fix libkexiv2 version for AltLangStrEdit::textEdit()
    
    it is part of current libkexiv2/master only (i.e. post 4.14.x, which
    is 2.3.x)

diff --git a/libs/imageproperties/captionedit.cpp b/libs/imageproperties/captionedit.cpp
index 88413fc..70bdb6d 100644
--- core/libs/imageproperties/captionedit.cpp
+++ core/libs/imageproperties/captionedit.cpp
@@ -202,7 +202,7 @@ void CaptionEdit::slotAuthorChanged(const QString& text)
 
 MsgTextEdit* CaptionEdit::textEdit() const
 {
-#if KEXIV2_VERSION >= 0x020302
+#if KEXIV2_VERSION >= 0x020400
     return d->altLangStrEdit->textEdit();
 #else
     return 0;
