$NetBSD: patch-apps_edit_src_drivers_printer.cpp,v 1.2 2019/06/08 11:04:27 rillig Exp $

--- apps/edit/src/drivers/printer.cpp.orig	2012-10-20 12:02:42.000000000 +0000
+++ apps/edit/src/drivers/printer.cpp
@@ -87,7 +87,8 @@ bool PrintDriver::OnPrintPage(int)
       // Multiply the points with the relative matrix
       for (int i = 0; i < 4; i++)
       {
-         corners[i].Transform(&GLOB->SCRDRV->GetInverseMappingMatrix());
+         wxTransformMatrix tmp(GLOB->SCRDRV->GetInverseMappingMatrix());
+         corners[i].Transform(&tmp);
       }
       x = (int) corners[0].GetX();
       y = (int) corners[0].GetY();
