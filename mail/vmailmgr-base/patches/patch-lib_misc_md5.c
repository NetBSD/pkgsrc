$NetBSD: patch-lib_misc_md5.c,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Provide modern prototypes.

--- lib/misc/md5.c.orig	2015-09-01 16:03:21.000000000 +0000
+++ lib/misc/md5.c
@@ -69,8 +69,7 @@ static const unsigned char fillbuf[64] =
 /* Initialize structure containing state of computation.
    (RFC 1321, 3.3: Step 3)  */
 void
-md5_init_ctx (ctx)
-     struct md5_ctx *ctx;
+md5_init_ctx (struct md5_ctx *ctx)
 {
   ctx->A = 0x67452301;
   ctx->B = 0xefcdab89;
@@ -87,9 +86,7 @@ md5_init_ctx (ctx)
    IMPORTANT: On some systems it is required that RESBUF is correctly
    aligned for a 32 bits value.  */
 void *
-md5_read_ctx (ctx, resbuf)
-     const struct md5_ctx *ctx;
-     void *resbuf;
+md5_read_ctx (const struct md5_ctx *ctx, void *resbuf)
 {
   ((md5_uint32 *) resbuf)[0] = SWAP (ctx->A);
   ((md5_uint32 *) resbuf)[1] = SWAP (ctx->B);
@@ -105,9 +102,7 @@ md5_read_ctx (ctx, resbuf)
    IMPORTANT: On some systems it is required that RESBUF is correctly
    aligned for a 32 bits value.  */
 void *
-md5_finish_ctx (ctx, resbuf)
-     struct md5_ctx *ctx;
-     void *resbuf;
+md5_finish_ctx (struct md5_ctx *ctx, void *resbuf)
 {
   /* Take yet unprocessed bytes into account.  */
   md5_uint32 bytes = ctx->buflen;
@@ -136,9 +131,7 @@ md5_finish_ctx (ctx, resbuf)
    resulting message digest number will be written into the 16 bytes
    beginning at RESBLOCK.  */
 int
-md5_stream (stream, resblock)
-     FILE *stream;
-     void *resblock;
+md5_stream (FILE *stream, void *resblock)
 {
   /* Important: BLOCKSIZE must be a multiple of 64.  */
 #define BLOCKSIZE 4096
@@ -193,10 +186,7 @@ md5_stream (stream, resblock)
    output yields to the wanted ASCII representation of the message
    digest.  */
 void *
-md5_buffer (buffer, len, resblock)
-     const char *buffer;
-     size_t len;
-     void *resblock;
+md5_buffer (const char *buffer, size_t len, void *resblock)
 {
   struct md5_ctx ctx;
 
@@ -212,10 +202,7 @@ md5_buffer (buffer, len, resblock)
 
 
 void
-md5_process_bytes (buffer, len, ctx)
-     const void *buffer;
-     size_t len;
-     struct md5_ctx *ctx;
+md5_process_bytes (const void *buffer, size_t len, struct md5_ctx *ctx)
 {
   /* When we already have some bits in our internal buffer concatenate
      both inputs first.  */
@@ -270,10 +257,7 @@ md5_process_bytes (buffer, len, ctx)
    It is assumed that LEN % 64 == 0.  */
 
 void
-md5_process_block (buffer, len, ctx)
-     const void *buffer;
-     size_t len;
-     struct md5_ctx *ctx;
+md5_process_block (const void *buffer, size_t len, struct md5_ctx *ctx)
 {
   md5_uint32 correct_words[16];
   const md5_uint32 *words = buffer;
