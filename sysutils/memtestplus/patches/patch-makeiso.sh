$NetBSD: patch-makeiso.sh,v 1.1 2013/12/08 00:35:28 jakllsch Exp $

--- makeiso.sh.orig	2013-08-10 02:03:33.000000000 +0000
+++ makeiso.sh
@@ -1,7 +1,7 @@
 #!/bin/sh
 
 # check to see if the correct tools are installed
-for X in wc genisoimage
+for X in wc mkisofs
 do
 	if [ "$(which $X)" = "" ]; then
 		echo "makeiso.sh error: $X is not in your path." >&2
@@ -37,7 +37,7 @@ cd cd
 echo -e "There is nothing to do here\r\r\nMemtest86+ is located on the bootsector of this CD\r\r\n" > README.TXT
 echo -e "Just boot from this CD and Memtest86+ will launch" >> README.TXT
 
-genisoimage -A "MKISOFS 1.1.2" -p "Memtest86+ 5.01" -publisher "Samuel D. <sdemeule@memtest.org>" -b boot/memtest.img -c boot/boot.catalog -V "MT501" -o memtest.iso .
+mkisofs -A "MKISOFS 1.1.2" -p "Memtest86+ 5.01" -publisher "Samuel D. <sdemeule@memtest.org>" -b boot/memtest.img -c boot/boot.catalog -V "MT501" -o memtest.iso .
 mv memtest.iso ../mt501.iso
 cd ..
 rm -rf cd
