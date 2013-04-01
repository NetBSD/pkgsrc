$NetBSD: patch-sfx2_inc_sfx2_controlwrapper.hxx,v 1.1 2013/04/01 12:19:14 joerg Exp $

--- sfx2/inc/sfx2/controlwrapper.hxx.orig	2013-03-30 17:31:36.000000000 +0000
+++ sfx2/inc/sfx2/controlwrapper.hxx
@@ -638,13 +638,13 @@ void MetricFieldWrapper< ValueT >::SetCo
 template< typename ValueT >
 ValueT ListBoxWrapper< ValueT >::GetControlValue() const
 {
-    return GetValueFromPos( this->GetControl().GetSelectEntryPos() );
+    return this->GetValueFromPos( this->GetControl().GetSelectEntryPos() );
 }
 
 template< typename ValueT >
 void ListBoxWrapper< ValueT >::SetControlValue( ValueT nValue )
 {
-    USHORT nPos = GetPosFromValue( nValue );
+    USHORT nPos = this->GetPosFromValue( nValue );
     if( nPos != this->GetNotFoundPos() )
         this->GetControl().SelectEntryPos( nPos );
 }
@@ -654,13 +654,13 @@ void ListBoxWrapper< ValueT >::SetContro
 template< typename ValueT >
 ValueT ValueSetWrapper< ValueT >::GetControlValue() const
 {
-    return GetValueFromPos( this->GetControl().GetSelectItemId() );
+    return this->GetValueFromPos( this->GetControl().GetSelectItemId() );
 }
 
 template< typename ValueT >
 void ValueSetWrapper< ValueT >::SetControlValue( ValueT nValue )
 {
-    USHORT nPos = GetPosFromValue( nValue );
+    USHORT nPos = this->GetPosFromValue( nValue );
     if( nPos != this->GetNotFoundPos() )
         this->GetControl().SelectItem( nPos );
 }
