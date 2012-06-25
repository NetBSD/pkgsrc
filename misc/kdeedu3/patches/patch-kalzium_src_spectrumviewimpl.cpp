$NetBSD: patch-kalzium_src_spectrumviewimpl.cpp,v 1.1 2012/06/25 11:31:20 joerg Exp $

--- kalzium/src/spectrumviewimpl.cpp.orig	2012-06-18 20:15:46.000000000 +0000
+++ kalzium/src/spectrumviewimpl.cpp
@@ -39,7 +39,8 @@ void SpectrumViewImpl::slotExportAsImage
 	                        this, i18n( "Save Spectrum" ) );
 	if( !fileName.isEmpty() )
 	{
-		if ( !exporter->saveAsImage( &m_spectrumWidget->pixmap(), fileName ) )
+		QPixmap p(m_spectrumWidget->pixmap());
+		if ( !exporter->saveAsImage( &p, fileName ) )
 			KMessageBox::error( this, i18n( "The spectrum could not be saved" ), i18n( "Image Could Not Be Saved") );
 	}	
 	delete exporter;
