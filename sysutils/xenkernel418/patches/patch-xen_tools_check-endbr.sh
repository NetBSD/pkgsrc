$NetBSD: patch-xen_tools_check-endbr.sh,v 1.1 2023/11/21 11:38:26 bouyer Exp $

For for NetBSD's stat(1)

--- ./xen/tools/check-endbr.sh.orig	2023-10-10 16:35:16.089399100 +0200
+++ ./xen/tools/check-endbr.sh	2023-10-10 16:41:12.764124684 +0200
@@ -96,7 +96,7 @@
 
 ${OBJCOPY} -j .text $1 -O binary $TEXT_BIN
 
-bin_sz=$(stat -c '%s' $TEXT_BIN)
+bin_sz=$(stat -f '%z' $TEXT_BIN)
 [ "$bin_sz" -ge $(((1 << 28) - $vma_lo)) ] &&
     { echo "$MSG_PFX Error: .text offsets must not exceed 256M" >&2; exit 1; }
 
@@ -116,8 +116,8 @@
 wait
 
 # Sanity check $VALID and $ALL, in case the string parsing bitrots
-val_sz=$(stat -c '%s' $VALID)
-all_sz=$(stat -c '%s' $ALL)
+val_sz=$(stat -f '%z' $VALID)
+all_sz=$(stat -f '%z' $ALL)
 [ "$val_sz" -eq 0 ]         && { echo "$MSG_PFX Error: Empty valid-addrs" >&2; exit 1; }
 [ "$all_sz" -eq 0 ]         && { echo "$MSG_PFX Error: Empty all-addrs" >&2; exit 1; }
 [ "$all_sz" -lt "$val_sz" ] && { echo "$MSG_PFX Error: More valid-addrs than all-addrs" >&2; exit 1; }
