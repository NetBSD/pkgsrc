$NetBSD: patch-htypes.h,v 1.1 2013/10/15 14:14:53 ryoon Exp $

--- htypes.h.orig	2013-06-14 21:32:42.000000000 +0000
+++ htypes.h
@@ -149,13 +149,16 @@ typedef  uint8_t    QWORD[16];  // unsig
   typedef  char *const *EXECV_ARG2_ARGV_T;
 #endif
 
-#if defined( OPTION_SCSI_TAPE ) && !defined( HAVE_SYS_MTIO_H )
+#if defined( OPTION_SCSI_TAPE ) && (!defined( HAVE_SYS_MTIO_H ) || defined(__NetBSD__))
   struct mt_tape_info
   {
-     long t_type;    /* device type id (mt_type) */
-     char *t_name;   /* descriptive name */
+     BYTE t_type;    /* device type id (mt_type) */
+     const char *t_name;   /* descriptive name */
   };
-  #define MT_TAPE_INFO   { { 0, NULL } }
+#define MT_ISUNKNOWN 0x01
+#define MT_ISQIC02 0x02 
+
+#define MT_TAPE_INFO { {MT_ISUNKNOWN, "Unknown type of tape device"}, {MT_ISQIC02, "Generic QIC-02 tape streamer"}, {0, NULL} }
 #endif
 
 /*-------------------------------------------------------------------*/
@@ -230,4 +233,47 @@ typedef int   DEVSR  (DEVBLK *dev, void 
 
 typedef BYTE *DEVIM;                    /* Immediate CCW Codes Table */
 
+#if defined(BSD) && BSD >= 199306
+/*-------------------------------------------------------------------*/
+/* Support for BSD tape                                              */
+/*-------------------------------------------------------------------*/
+/* Generic Mag Tape (device independent) status macros for examining
+ * mt_gstat -- HP-UX compatible.
+ * There is room for more generic status bits here, but I don't
+ * know which of them are reserved. At least three or so should
+ * be added to make this really useful.
+ */
+#define GMT_EOF(x)              ((x) & 0x80000000)
+#define GMT_BOT(x)              ((x) & 0x40000000)
+#define GMT_EOT(x)              ((x) & 0x20000000)
+#define GMT_SM(x)               ((x) & 0x10000000)  /* DDS setmark */
+#define GMT_EOD(x)              ((x) & 0x08000000)  /* DDS EOD */
+#define GMT_WR_PROT(x)          ((x) & 0x04000000)
+/* #define GMT_ ? ((x) & 0x02000000) */
+#define GMT_ONLINE(x)           ((x) & 0x01000000)
+#define GMT_D_6250(x)           ((x) & 0x00800000)
+#define GMT_D_1600(x)           ((x) & 0x00400000)
+#define GMT_D_800(x)            ((x) & 0x00200000)
+/* #define GMT_ ? ((x) & 0x00100000) */
+/* #define GMT_ ? ((x) & 0x00080000) */
+#define GMT_DR_OPEN(x)          ((x) & 0x00040000)  /* door open (no tape) */
+/* #define GMT_ ? ((x) & 0x00020000) */
+#define GMT_IM_REP_EN(x)        ((x) & 0x00010000)  /* immediate report mode */
+/* 16 generic status bits unused */
+/* SCSI-tape specific definitions */
+
+/* Bitfield shifts in the status */
+#define MT_ST_BLKSIZE_SHIFT 0
+#define MT_ST_BLKSIZE_MASK 0xffffff
+#define MT_ST_DENSITY_SHIFT 24
+#define MT_ST_DENSITY_MASK 0xff000000
+
+#define MTSETBLK 20     /* set block length (SCSI) */
+
+#define MTIOCPOS	MTNOP	/* do nothing, status only */
+//#define mtpos		mtget	/* generic status struct, including mt_blkno */
+#define MTSEEK		MTFSR	/* forward seek record; probably wrong */
+
+#endif /* BSD */
+
 #endif // _HTYPES_H_
