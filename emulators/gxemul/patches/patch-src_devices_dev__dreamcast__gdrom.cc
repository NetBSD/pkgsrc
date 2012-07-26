$NetBSD: patch-src_devices_dev__dreamcast__gdrom.cc,v 1.1 2012/07/26 22:10:28 abs Exp $

Fake up a much more complete TOC based on real CD image.
Now works with NetBSD 4, 5 & 6 which would have previously failed.

Comment out some unusual sector subtractions which handled values in the
multigigabyte range.

--- src/devices/dev_dreamcast_gdrom.cc.orig	2010-02-14 09:33:52.000000000 +0000
+++ src/devices/dev_dreamcast_gdrom.cc
@@ -109,12 +109,37 @@ static void handle_command(struct cpu *c
 		}
 		alloc_data(d);
 
-		/*  TODO: Fill TOC in a better way  */
-		d->data[99*4] = 1;	/*  First track  */
-		d->data[100*4] = 2;	/*  Last track  */
+		/*
+		TOC from test booted real CD image on NetBSD/dreamcast
+		01000096,41002e4c,ffffffff * 97,01010000,41020000,6100e641,
+		*/
+		memset(d->data, 0xff, d->cnt); /* Default data to 0xff */
+
+		d->data[0*4]   = 0x10;	/* Track 1 */
+		d->data[0*4+1] = 0;
+		d->data[0*4+2] = 0;
+		d->data[0*4+3] = 0x96;
+
+		d->data[1*4]   = 0x41;	/* Track 2 */
+		d->data[1*4+1] = 0;
+		d->data[1*4+2] = 0x2e;
+		d->data[1*4+3] = 0x4c;
+
+		d->data[99*4]   = 0x01;	/*  First track  */
+		d->data[99*4+1] = 0x01;
+		d->data[99*4+2] = 0;
+		d->data[99*4+3] = 0;
+
+		d->data[100*4]   = 0x41; /*  Last track  */
+		d->data[100*4+1] = 0x02;
+		d->data[100*4+2] = 0;
+		d->data[100*4+3] = 0;
+
+		d->data[101*4]   = 0x61; /*  Leadout  */
+		d->data[101*4+1] = 0;
+		d->data[101*4+2] = 0xe6;
+		d->data[101*4+3] = 0x41;
 
-		d->data[0*4] = 0x10;	/*  Track 1  */
-		d->data[1*4] = 0x10;	/*  Track 2  */
 		break;
 
 	case 0x30:
@@ -126,6 +151,7 @@ static void handle_command(struct cpu *c
 		}
 		sector_nr = d->cmd[2] * 65536 + d->cmd[3] * 256 + d->cmd[4];
 		sector_count = d->cmd[8] * 65536 + d->cmd[9] * 256 + d->cmd[10];
+
 		if (d->cnt == 0)
 			d->cnt = 65536;
 		alloc_data(d);
@@ -136,9 +162,17 @@ static void handle_command(struct cpu *c
 		}
 
 {
+
+/* Definitely not needed for NetBSD - unknown if needed for anything else? */
+#if 0
 if (sector_nr >= 1376810)
 	sector_nr -= 1376810;
+#endif
+
 sector_nr -= 150;
+
+/* Definitely not needed for NetBSD - unknown if needed for anything else? */
+#if 0
 if (sector_nr > 1048576)
 	sector_nr -= 1048576;
 /*  printf("sector nr = %i\n", (int)sector_nr);  */
@@ -146,6 +180,7 @@ if (sector_nr > 1048576)
 if (sector_nr < 1000)
 	sector_nr += (diskimage_get_baseoffset(cpu->machine, 0, DISKIMAGE_IDE)
 	 / 2048);
+#endif
 }
 
 		res = diskimage_access(cpu->machine, 0, DISKIMAGE_IDE,
