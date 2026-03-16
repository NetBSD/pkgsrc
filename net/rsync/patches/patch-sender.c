$NetBSD: patch-sender.c,v 1.1 2026/03/16 16:05:56 kim Exp $

https://github.com/RsyncProject/rsync/commit/797e17fc4a6f15e3b1756538a9f812b63942686f.patch

From: Andrew Tridgell <andrew@tridgell.net>
Date: Sat, 23 Aug 2025 17:26:53 +1000
Subject: [PATCH] fixed an invalid access to files array

this was found by Calum Hutton from Rapid7. It is a real bug, but
analysis shows it can't be leverged into an exploit. Worth fixing
though.

Many thanks to Calum and Rapid7 for finding and reporting this
---
 sender.c | 2 ++
 1 file changed, 2 insertions(+)

diff --git a/sender.c b/sender.c
index a4d46c39e..b1588b701 100644
--- sender.c
+++ sender.c
@@ -262,6 +262,8 @@ void send_files(int f_in, int f_out)
 
 		if (ndx - cur_flist->ndx_start >= 0)
 			file = cur_flist->files[ndx - cur_flist->ndx_start];
+		else if (cur_flist->parent_ndx < 0)
+			exit_cleanup(RERR_PROTOCOL);
 		else
 			file = dir_flist->files[cur_flist->parent_ndx];
 		if (F_PATHNAME(file)) {
