$NetBSD: patch-hstructs.h,v 1.1 2011/05/01 23:28:59 ryoon Exp $

--- hstructs.h.orig	2010-02-12 23:58:38.000000000 +0000
+++ hstructs.h
@@ -1025,9 +1025,13 @@ struct DEVBLK {                         
         U32     msgid;                  /* Message Id of async. i/o  */
 #if defined(OPTION_SCSI_TAPE)
         struct mtget mtget;             /* SCSI tape status struct   */
+#if (defined(BSD) && BSD >= 199306)
+#define sstat  mtget.mt_erreg
+#else
 #define sstat  mtget.mt_gstat           /* Generic SCSI tape device-
                                            independent status field;
                                            (struct mtget->mt_gstat)  */
+#endif
         TID     stape_mountmon_tid;     /* Tape-mount monitor thread */
         u_int   stape_close_rewinds:1;  /* 1=Rewind at close         */
         u_int   stape_blkid_32:1;       /* 1=block-ids are 32 bits   */
@@ -1039,7 +1043,11 @@ struct DEVBLK {                         
         COND    stape_getstat_cond;     /* COND for status wrkr thrd */
         COND    stape_exit_cond;        /* thread wait for exit COND */
         struct mtget stape_getstat_mtget;/* status wrkr thrd status  */
+#if (defined(BSD) && BSD >= 199306)
+#define stape_getstat_sstat  stape_getstat_mtget.mt_erreg
+#else
 #define stape_getstat_sstat stape_getstat_mtget.mt_gstat /* (gstat)  */
+#endif
         struct timeval
                 stape_getstat_query_tod;/* TOD of actual drive query */
 #endif
