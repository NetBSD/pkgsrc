$NetBSD: patch-reportdesign_source_core_api_ReportDefinition.cxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- reportdesign/source/core/api/ReportDefinition.cxx.orig	2014-08-24 21:06:11.000000000 +0000
+++ reportdesign/source/core/api/ReportDefinition.cxx
@@ -1623,8 +1623,9 @@ void SAL_CALL OReportDefinition::switchT
         m_pImpl->m_pObjectContainer->SwitchPersistence(m_pImpl->m_xStorage);
     }
     // notify our container listeners
+    OWeakObject *weakObjectThis = static_cast<OWeakObject*>(this);
     m_pImpl->m_aStorageChangeListeners.forEach<document::XStorageChangeListener>(
-            ::boost::bind(&document::XStorageChangeListener::notifyStorageChange,_1,boost::cref(static_cast<OWeakObject*>(this)),boost::cref(_xStorage)));
+            ::boost::bind(&document::XStorageChangeListener::notifyStorageChange,_1,boost::cref(weakObjectThis),boost::cref(_xStorage)));
 }
 // -----------------------------------------------------------------------------
 uno::Reference< embed::XStorage > SAL_CALL OReportDefinition::getDocumentStorage(  ) throw (io::IOException, uno::Exception, uno::RuntimeException)
