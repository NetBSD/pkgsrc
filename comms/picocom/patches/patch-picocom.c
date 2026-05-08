$NetBSD: patch-picocom.c,v 1.1 2026/05/08 02:52:30 khorben Exp $

Avoid a potential use after free condition:

cc -O2 -Wall -g  -DVERSION_STR=\"3.1\" -DTTY_Q_SZ=0 -DHIGH_BAUD -DUSE_FLOCK -DHISTFILE=\".picocom_history\"  -DLINENOISE -o picocom.o -c picocom.c
picocom.c: In function 'read_baud':                                                                                                                                                                                                          
picocom.c:608:9: warning: pointer 'baudstr' may be used after 'free' [-Wuse-after-free]                                                                                                                                                      
  608 |         add_history(baudstr);                                                                                                                                                                                                        
      |         ^~~~~~~~~~~~~~~~~~~~                                                                                                                                                                                                         
picocom.c:604:9: note: call to 'free' here                                                                                                                                                                                                   
  604 |         free(baudstr);                                                                                                                                                                                                               
      |         ^~~~~~~~~~~~~                                                                                                                                                                                                                

--- picocom.c.orig	2026-04-26 13:38:46.249642608 +0000
+++ picocom.c
@@ -601,12 +601,12 @@ read_baud (void)
             fd_printf(STO, "*** Invalid baudrate!");
             baud = -1;
         }
+
+	if (baud >= 0 && baudstr != NULL)
+		add_history(baudstr);
         free(baudstr);
     } while (baud < 0);
 
-    if (baudstr != NULL)
-        add_history(baudstr);
-
     return baud;
 }
 
