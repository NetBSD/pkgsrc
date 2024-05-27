$NetBSD: patch-erts_emulator_drivers_win32_registry__drv.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- erts/emulator/drivers/win32/registry_drv.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ erts/emulator/drivers/win32/registry_drv.c
@@ -128,7 +128,7 @@ reg_start(ErlDrvPort port, char* buf)
     REGSAM sam = KEY_READ;
 
     if ((s = strchr(buf, ' ')) != NULL) {
-	while (isspace(*s))
+	while (isspace((unsigned char)*s))
 	    s++;
 	while (*s != '\0') {
 	    if (*s == 'r') {
@@ -417,7 +417,7 @@ reply(RegPort* rp, LONG result)
 	sbuf[0] = 'e';
 	err = maperror(result);
 	for (s = erl_errno_id(err), t = sbuf+1; *s; s++, t++) {
-	    *t = tolower(*s);
+	    *t = tolower((unsigned char)*s);
 	}
 	driver_output(rp->port, sbuf, t-sbuf);
     }
