$NetBSD: patch-platform_x11_pdfapp.c,v 1.3 2023/09/07 14:36:54 vins Exp $

* Implement fine-grained zoom control (from OpenBSD ports).
* Fix up/down scrolling with vi-like keys (from FreeBSD ports).

--- platform/x11/pdfapp.c.orig	2023-09-05 11:51:19.000000000 +0000
+++ platform/x11/pdfapp.c
@@ -175,11 +175,21 @@ static void pdfapp_sleep(int ms)
 static void pdfapp_showpage(pdfapp_t *app, int loadpage, int drawpage, int repaint, int transition, int searching);
 
 static const int zoomlist[] = {
-	18, 24, 36, 54, 72, 96, 120, 144, 180,
-	216, 288, 360, 432, 504, 576, 648, 720,
-	792, 864, 936, 1008, 1080, 1152
+	18, 21, 24, 30, 36, 44, 54, 62, 72, 83, 96, 107, 120, 131, 144, 160, 180, 197,
+	216, 250, 288, 322, 360, 394, 432, 466, 504, 538, 576, 610, 648, 682, 720, 754,
+	792, 826, 864, 898, 936, 970, 1008, 1042, 1080, 1114, 1152
 };
 
+static int fine_zoom_in(int oldres)
+{
+	return oldres+1;
+}
+
+static int fine_zoom_out(int oldres)
+{
+	return oldres-1;
+}
+
 static int zoom_in(int oldres)
 {
 	int i;
@@ -1538,6 +1548,8 @@ key_rewritten:
 
 	case 'j':
 		{
+			if (app->pany + app->imgh <= app->winh)
+			  goto pagedown;
 			if (app->imgh <= app->winh || app->pany <= app->winh - app->imgh)
 			{
 				panto = PAN_TO_TOP;
@@ -1553,6 +1565,8 @@ key_rewritten:
 
 	case 'k':
 		{
+			if (app->pany >= 0)
+			  goto pageup;
 			if (app->imgh <= app->winh || app->pany == 0)
 			{
 				panto = PAN_TO_BOTTOM;
@@ -1627,6 +1641,7 @@ key_rewritten:
 	 */
 
 	case ',':
+		pageup:
 		panto = DONT_PAN;
 		if (app->numberlen > 0)
 			app->pageno -= atoi(app->number);
@@ -1635,6 +1650,7 @@ key_rewritten:
 		break;
 
 	case '.':
+		pagedown:
 		panto = DONT_PAN;
 		if (app->numberlen > 0)
 			app->pageno += atoi(app->number);
@@ -1642,6 +1658,7 @@ key_rewritten:
 			app->pageno++;
 		break;
 
+	case '\b': /* backspace */
 	case 'b':
 		{
 			int number = 1;
@@ -1688,7 +1705,7 @@ key_rewritten:
 				{
 					if (app->imgw + app->panx <= app->winw + app->imgw/20)
 					{
-						if (app->pageno + 1 <= app->pagecount)
+						if (app->pageno <= app->pagecount)
 						{
 							app->panx = 0;
 							app->pany = 0;
@@ -1800,9 +1817,9 @@ static void handlescroll(pdfapp_t *app, 
 	{
 		/* zoom in/out if ctrl is pressed */
 		if (dir > 0)
-			app->resolution = zoom_in(app->resolution);
+			app->resolution = ((modifiers & (1<<0)) ? fine_zoom_in : zoom_in)(app->resolution);
 		else
-			app->resolution = zoom_out(app->resolution);
+			app->resolution = ((modifiers & (1<<0)) ? fine_zoom_out : zoom_out)(app->resolution);
 		if (app->resolution > MAXRES)
 			app->resolution = MAXRES;
 		if (app->resolution < MINRES)
