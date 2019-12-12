$NetBSD: patch-platform_x11_pdfapp.c,v 1.1 2019/12/12 14:35:55 leot Exp $

Fix ` ' on the last page.

When ` ' (space) is pressed on the second to last page it doesn't
go to the last page.  Adjust the check to DTRT.

Also fixed upstream via commit 606fcf8383943d7f986d6706f1cb67fbdab0e224.

--- platform/x11/pdfapp.c.orig	2019-08-02 14:49:26.000000000 +0000
+++ platform/x11/pdfapp.c
@@ -1503,7 +1503,7 @@ void pdfapp_onkey(pdfapp_t *app, int c, 
 		{
 			if (app->imgw + app->panx <= app->winw)
 			{
-				if (app->pageno + 1 < app->pagecount)
+				if (app->pageno + 1 <= app->pagecount)
 				{
 					app->panx = 0;
 					app->pany = 0;
