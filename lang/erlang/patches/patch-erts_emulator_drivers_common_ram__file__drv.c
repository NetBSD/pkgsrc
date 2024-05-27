$NetBSD: patch-erts_emulator_drivers_common_ram__file__drv.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- erts/emulator/drivers/common/ram_file_drv.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ erts/emulator/drivers/common/ram_file_drv.c
@@ -211,7 +211,7 @@ static int error_reply(RamFile *f, int e
      */
     response[0] = RAM_FILE_RESP_ERROR;
     for (s = erl_errno_id(err), t = response+1; *s; s++, t++)
-	*t = tolower(*s);
+	*t = tolower((unsigned char)*s);
     driver_output2(f->port, response, t-response, NULL, 0);
     return 0;
 }
