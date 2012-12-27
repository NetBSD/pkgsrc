$NetBSD: patch-src_rt_rv2.c,v 1.1 2012/12/27 00:23:21 dholland Exp $

Pass around input buffer lengths.

--- src/rt/rv2.c~	2004-04-10 02:54:10.000000000 +0000
+++ src/rt/rv2.c
@@ -96,7 +96,7 @@ getview(				/* get/show view parameters 
 	}
 	sprintf(buf, "view type (%c): ", ourview.type);
 	(*dev->comout)(buf);
-	(*dev->comin)(buf, NULL);
+	(*dev->comin)(buf, sizeof(buf), NULL);
 	if (buf[0] == CTRL('C')) return;
 	if (buf[0] && buf[0] != ourview.type) {
 		nv.type = buf[0];
@@ -106,7 +106,7 @@ getview(				/* get/show view parameters 
 	sprintf(buf, "view point (%.6g %.6g %.6g): ",
 			ourview.vp[0], ourview.vp[1], ourview.vp[2]);
 	(*dev->comout)(buf);
-	(*dev->comin)(buf, NULL);
+	(*dev->comin)(buf, sizeof(buf), NULL);
 	if (buf[0] == CTRL('C')) return;
 	if (sscanvec(buf, nv.vp))
 		change++;
@@ -115,7 +115,7 @@ getview(				/* get/show view parameters 
 	sprintf(buf, "view direction (%.6g %.6g %.6g): ",
 			ourview.vdir[0], ourview.vdir[1], ourview.vdir[2]);
 	(*dev->comout)(buf);
-	(*dev->comin)(buf, NULL);
+	(*dev->comin)(buf, sizeof(buf), NULL);
 	if (buf[0] == CTRL('C')) return;
 	if (sscanvec(buf, nv.vdir))
 		change++;
@@ -124,7 +124,7 @@ getview(				/* get/show view parameters 
 	sprintf(buf, "view up (%.6g %.6g %.6g): ",
 			ourview.vup[0], ourview.vup[1], ourview.vup[2]);
 	(*dev->comout)(buf);
-	(*dev->comin)(buf, NULL);
+	(*dev->comin)(buf, sizeof(buf), NULL);
 	if (buf[0] == CTRL('C')) return;
 	if (sscanvec(buf, nv.vup))
 		change++;
@@ -133,7 +133,7 @@ getview(				/* get/show view parameters 
 	sprintf(buf, "view horiz and vert size (%.6g %.6g): ",
 			ourview.horiz, ourview.vert);
 	(*dev->comout)(buf);
-	(*dev->comin)(buf, NULL);
+	(*dev->comin)(buf, sizeof(buf), NULL);
 	if (buf[0] == CTRL('C')) return;
 	if (sscanf(buf, "%lf %lf", &nv.horiz, &nv.vert) == 2)
 		change++;
@@ -143,7 +143,7 @@ getview(				/* get/show view parameters 
 	sprintf(buf, "fore and aft clipping plane (%.6g %.6g): ",
 			ourview.vfore, ourview.vaft);
 	(*dev->comout)(buf);
-	(*dev->comin)(buf, NULL);
+	(*dev->comin)(buf, sizeof(buf), NULL);
 	if (buf[0] == CTRL('C')) return;
 	if (sscanf(buf, "%lf %lf", &nv.vfore, &nv.vaft) == 2)
 		change++;
@@ -153,7 +153,7 @@ getview(				/* get/show view parameters 
 	sprintf(buf, "view shift and lift (%.6g %.6g): ",
 			ourview.hoff, ourview.voff);
 	(*dev->comout)(buf);
-	(*dev->comin)(buf, NULL);
+	(*dev->comin)(buf, sizeof(buf), NULL);
 	if (buf[0] == CTRL('C')) return;
 	if (sscanf(buf, "%lf %lf", &nv.hoff, &nv.voff) == 2)
 		change++;
@@ -404,7 +404,7 @@ getexposure(				/* get new exposure */
 			if (*cp == '\0') {	/* interactive */
 				sprintf(buf, "exposure (%f): ", exposure);
 				(*dev->comout)(buf);
-				(*dev->comin)(buf, NULL);
+				(*dev->comin)(buf, sizeof(buf), NULL);
 				for (cp = buf; isspace(*cp); cp++)
 					;
 				if (*cp == '\0')
@@ -454,7 +454,7 @@ getparam(		/* get variable from user */
 			(*dev->comout)(dsc);
 			sprintf(buf, " (%d): ", ptr->i);
 			(*dev->comout)(buf);
-			(*dev->comin)(buf, NULL);
+			(*dev->comin)(buf, sizeof(buf), NULL);
 			if (sscanf(buf, "%d", &i0) != 1)
 				return(0);
 		}
@@ -465,7 +465,7 @@ getparam(		/* get variable from user */
 			(*dev->comout)(dsc);
 			sprintf(buf, " (%.6g): ", ptr->d);
 			(*dev->comout)(buf);
-			(*dev->comin)(buf, NULL);
+			(*dev->comin)(buf, sizeof(buf), NULL);
 			if (sscanf(buf, "%lf", &d0) != 1)
 				return(0);
 		}
@@ -476,7 +476,7 @@ getparam(		/* get variable from user */
 			(*dev->comout)(dsc);
 			sprintf(buf, "? (%c): ", ptr->i ? 'y' : 'n');
 			(*dev->comout)(buf);
-			(*dev->comin)(buf, NULL);
+			(*dev->comin)(buf, sizeof(buf), NULL);
 			if (buf[0] == '\0' ||
 					strchr("yY+1tTnN-0fF", buf[0]) == NULL)
 				return(0);
@@ -491,7 +491,7 @@ getparam(		/* get variable from user */
 					colval(ptr->C,GRN),
 					colval(ptr->C,BLU));
 			(*dev->comout)(buf);
-			(*dev->comin)(buf, NULL);
+			(*dev->comin)(buf, sizeof(buf), NULL);
 			if (sscanf(buf, "%lf %lf %lf", &d0, &d1, &d2) != 3)
 				return(0);
 		}
@@ -512,7 +512,7 @@ setparam(				/* get/set program paramete
 	if (s[0] == '\0') {
 		(*dev->comout)(
 		"aa ab ad ar as av aw b dc dv dj ds dt i lr lw me ma mg ms ps pt sj st bv: ");
-		(*dev->comin)(buf, NULL);
+		(*dev->comin)(buf, sizeof(buf), NULL);
 		s = buf;
 	}
 	switch (s[0]) {
@@ -725,7 +725,7 @@ char  *s;
 			sprintf(buf+strlen(buf), " in %s \"%s\"",
 					ofun[ino->otype].funame, ino->oname);
 		(*dev->comout)(buf);
-		(*dev->comin)(buf, NULL);
+		(*dev->comin)(buf, sizeof(buf), NULL);
 		if (thisray.rot >= FHUGE)
 			(*dev->comout)("at infinity");
 		else {
@@ -734,7 +734,7 @@ char  *s;
 					thisray.rop[2], thisray.rt);
 			(*dev->comout)(buf);
 		}
-		(*dev->comin)(buf, NULL);
+		(*dev->comin)(buf, sizeof(buf), NULL);
 		sprintf(buf, "value (%.5g %.5g %.5g) (%.3gL)",
 				colval(thisray.rcol,RED),
 				colval(thisray.rcol,GRN),
@@ -742,7 +742,7 @@ char  *s;
 				luminance(thisray.rcol));
 		(*dev->comout)(buf);
 	}
-	(*dev->comin)(buf, NULL);
+	(*dev->comin)(buf, sizeof(buf), NULL);
 }
 
 
