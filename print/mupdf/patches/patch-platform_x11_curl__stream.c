$NetBSD: patch-platform_x11_curl__stream.c,v 1.2 2023/09/07 14:52:50 vins Exp $

offset is a 64-bit integer.

--- platform/x11/curl_stream.c.orig	2023-09-05 11:51:19.000000000 +0000
+++ platform/x11/curl_stream.c
@@ -397,7 +397,7 @@ static int cs_next(fz_context *ctx, fz_s
 	{
 		unlock(state);
 		if (state->data_arrived == 0)
-			fz_throw(ctx, err_type, "read of a block we don't have (A) (offset=%ld)", read_point);
+			fz_throw(ctx, err_type, "read of a block we don't have (A) (offset=%lld)", read_point);
 		return EOF;
 	}
 
@@ -411,7 +411,7 @@ static int cs_next(fz_context *ctx, fz_s
 		if (read_point + len > state->current_fill_start)
 		{
 			unlock(state);
-			fz_throw(ctx, err_type, "read of a block we don't have (B) (offset=%ld)", read_point);
+			fz_throw(ctx, err_type, "read of a block we don't have (B) (offset=%lld)", read_point);
 		}
 		memcpy(buf, state->buffer + read_point, len);
 		unlock(state);
@@ -434,7 +434,7 @@ static int cs_next(fz_context *ctx, fz_s
 		{
 			state->next_fill_start = block<<BLOCK_SHIFT;
 			unlock(state);
-			fz_throw(ctx, err_type, "read of a block we don't have (C) (offset=%ld)", read_point);
+			fz_throw(ctx, err_type, "read of a block we don't have (C) (offset=%lld)", read_point);
 		}
 		block++;
 		memcpy(buf, state->buffer + read_point, left_over);
@@ -457,7 +457,7 @@ static int cs_next(fz_context *ctx, fz_s
 			stream->pos += len_read;
 			/* If we haven't fetched anything, throw. */
 			if (len_read == 0)
-				fz_throw(ctx, err_type, "read of a block we don't have (D) (offset=%ld)", read_point);
+				fz_throw(ctx, err_type, "read of a block we don't have (D) (offset=%lld)", read_point);
 			/* Otherwise, we got at least one byte, so we can safely return that. */
 			return *stream->rp++;
 		}
@@ -482,7 +482,7 @@ static int cs_next(fz_context *ctx, fz_s
 			stream->pos += len_read;
 			/* If we haven't fetched anything, throw. */
 			if (len_read == 0)
-				fz_throw(ctx, err_type, "read of a block we don't have (E) (offset=%ld)", read_point);
+				fz_throw(ctx, err_type, "read of a block we don't have (E) (offset=%lld)", read_point);
 			/* Otherwise, we got at least one byte, so we can safely return that. */
 			return *stream->rp++;
 		}
