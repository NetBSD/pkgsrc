$NetBSD: patch-hstructs.h,v 1.2 2013/10/15 14:14:53 ryoon Exp $

--- hstructs.h.orig	2013-06-14 21:32:42.000000000 +0000
+++ hstructs.h
@@ -1105,9 +1105,13 @@ struct DEVBLK {                         
         u_int   write_immed:1;          /* 1=Write-Immediate mode    */
 #if defined(OPTION_SCSI_TAPE)
         struct mtget mtget;             /* SCSI tape status struct   */
+#if (defined(BSD) && BSD >= 199306)
+#define sstat  mtget.mt_erreg
+#else
 #define sstat  mtget.mt_gstat           /* Generic SCSI tape device-
                                            independent status field;
                                            (struct mtget->mt_gstat)  */
+#endif
         u_int   stape_close_rewinds:1;  /* 1=Rewind at close         */
         u_int   stape_blkid_32:1;       /* 1=block-ids are 32 bits   */
         u_int   stape_no_erg:1;         /* 1=ignore Erase Gap CCWs   */
