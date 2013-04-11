$NetBSD: patch-blktap_drivers_block-qcow.c,v 1.1 2013/04/11 19:57:53 joerg Exp $

--- blktap/drivers/block-qcow.c.orig	2013-03-28 16:51:10.000000000 +0000
+++ blktap/drivers/block-qcow.c
@@ -1078,7 +1078,8 @@ static int tdqcow_close(struct disk_driv
 		offset = sizeof(QCowHeader) + sizeof(uint32_t);
 		lseek(fd, offset, SEEK_SET);
 		out = cpu_to_be32(cksum);
-		if (write(fd, &out, sizeof(uint32_t))) ;
+		if (write(fd, &out, sizeof(uint32_t)))
+			;
 		close(fd);
 	}
 
