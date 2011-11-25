$NetBSD: patch-kphone_kcallwidget.cpp,v 1.1 2011/11/25 22:13:29 joerg Exp $

--- kphone/kcallwidget.cpp.orig	2011-11-25 19:09:05.000000000 +0000
+++ kphone/kcallwidget.cpp
@@ -89,13 +89,10 @@ void KCallTransfer::slotCancel( void )
 }
 
 KCallWidget::KCallWidget( KSipAuthentication *auth, CallAudio *callaudio, SipCall *initcall, KPhoneView *parent, const char *name )
-	: call( initcall ), phoneView( parent )
+	: QDialog( call->getSubject() == tr("Incoming call") ? NULL : parent,
+	           name, FALSE, WStyle_DialogBorder),
+	  call( initcall ),phoneView( parent )
 {
-	if( call->getSubject() == tr("Incoming call") )
-		QDialog::QDialog( NULL, name, FALSE, WStyle_DialogBorder );
-	else
-		QDialog::QDialog( parent, name, FALSE, WStyle_DialogBorder );
-		
 	sipauthentication = auth;
 	missedCalls.setAutoDelete( true );
 	receivedCalls.setAutoDelete( true );
