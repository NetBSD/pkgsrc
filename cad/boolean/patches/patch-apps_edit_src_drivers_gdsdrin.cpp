$NetBSD: patch-apps_edit_src_drivers_gdsdrin.cpp,v 1.1 2012/11/16 00:32:50 joerg Exp $

--- apps/edit/src/drivers/gdsdrin.cpp.orig	2012-11-15 14:12:33.000000000 +0000
+++ apps/edit/src/drivers/gdsdrin.cpp
@@ -543,8 +543,8 @@ bool GDS_driver_in::ReadArrayReference(S
       ReadString(strname);
       _aref->SetStructureReferenceName(strname);
 
-      Strans* _strans = new Strans();
-      ReadStrans(_strans);
+      Strans* _strans2 = new Strans();
+      ReadStrans(_strans2);
 
 
 		if (!ReadHeader(GDS_COLROW))
@@ -576,17 +576,17 @@ bool GDS_driver_in::ReadArrayReference(S
       _relative_matrix = new wxTransformMatrix();
 
       // Mirror in X if necessary
-      if (_strans->GetReflection())
+      if (_strans2->GetReflection())
          _relative_matrix->Mirror();
 
       //  Rotate if necessary
-      if (_strans->GetAbsAngle() == 0)
-         _relative_matrix->Rotate(_strans->GetAngle(), 0, 0);
+      if (_strans2->GetAbsAngle() == 0)
+         _relative_matrix->Rotate(_strans2->GetAngle(), 0, 0);
 
       // Scale if necessary
-      if (_strans->GetAbsScale() == 0)
+      if (_strans2->GetAbsScale() == 0)
       {
-         EIGHT_G_BYTE_REAL scale = _strans->GetScale();
+         EIGHT_G_BYTE_REAL scale = _strans2->GetScale();
          _relative_matrix->Scale(scale, scale, 0, 0);
       }
 
@@ -599,7 +599,7 @@ bool GDS_driver_in::ReadArrayReference(S
       _structure->insend(_aref);
 
       delete _Point;
-      delete _strans;
+      delete _strans2;
       delete _relative_matrix;
    }
 	catch (GDS_Error& _error)
