$NetBSD: patch-mbox.c,v 1.1 2013/05/12 17:26:46 uwe Exp $

Make argument type match conversion specifier to print correct numbers
on big-endian systems.

--- mbox.c.orig	2007-05-23 01:17:53.000000000 +0000
+++ mbox.c
@@ -127,7 +127,7 @@ int mmdf_parse_mailbox (CONTEXT *ctx)
       count++;
       if (!ctx->quiet && ReadInc && ((count % ReadInc == 0) || count == 1))
 	mutt_message (_("Reading %s... %d (%d%%)"), ctx->path, count,
-		      loc / (ctx->size / 100 + 1));
+		      (int)(loc / (ctx->size / 100 + 1)));
 
 
       if (ctx->msgcount == ctx->hdrmax)
@@ -288,7 +288,7 @@ int mbox_parse_mailbox (CONTEXT *ctx)
 
       if (!ctx->quiet && ReadInc && ((count % ReadInc == 0) || count == 1))
 	mutt_message (_("Reading %s... %d (%d%%)"), ctx->path, count,
-		      ftell (ctx->fp) / (ctx->size / 100 + 1));
+		      (int)(ftell (ctx->fp) / (ctx->size / 100 + 1)));
 
       if (ctx->msgcount == ctx->hdrmax)
 	mx_alloc_memory (ctx);
@@ -796,7 +796,7 @@ int mbox_sync_mailbox (CONTEXT *ctx, int
       j++;
       if (!ctx->quiet && WriteInc && ((i % WriteInc) == 0 || j == 1))
 	mutt_message (_("Writing messages... %d (%d%%)"), i,
-		      ftell (ctx->fp) / (ctx->size / 100 + 1));
+		      (int)(ftell (ctx->fp) / (ctx->size / 100 + 1)));
 
       if (ctx->magic == M_MMDF)
       {
