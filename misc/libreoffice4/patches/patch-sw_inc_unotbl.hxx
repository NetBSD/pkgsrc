$NetBSD: patch-sw_inc_unotbl.hxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- sw/inc/unotbl.hxx.orig	2014-01-18 19:14:52.000000000 +0000
+++ sw/inc/unotbl.hxx
@@ -71,7 +71,7 @@ class SwXCell : public SwXCellBaseClass,
     public SwClient
 {
     friend void   sw_setString( SwXCell &rCell, const OUString &rTxt,
-                                 sal_Bool bKeepNumberFmt = sal_False );
+                                 sal_Bool bKeepNumberFmt );
     friend double sw_getValue( SwXCell &rCell );
     friend void   sw_setValue( SwXCell &rCell, double nVal );
 
@@ -160,6 +160,8 @@ public:
     SwFrmFmt* GetFrmFmt() const { return (SwFrmFmt*)GetRegisteredIn(); }
 };
 
+void   sw_setString( SwXCell &rCell, const OUString &rTxt, sal_Bool bKeepNumberFmt = sal_False );
+
 class SwXTextTableRow : public cppu::WeakImplHelper2
 <
     ::com::sun::star::beans::XPropertySet,
