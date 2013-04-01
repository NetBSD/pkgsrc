$NetBSD: patch-chart2_source_controller_main_ChartController.hxx,v 1.1 2013/04/01 12:19:13 joerg Exp $

--- chart2/source/controller/main/ChartController.hxx.orig	2013-03-30 19:56:42.000000000 +0000
+++ chart2/source/controller/main/ChartController.hxx
@@ -533,7 +533,7 @@ private:
 		        TheModel* operator->() const { return m_pTheModel; }
 		private:
 			TheModel*				m_pTheModel;
-			mutable ::osl::Mutex&	m_rModelMutex;
+			::osl::Mutex&	m_rModelMutex;
 	};
 
 private:
