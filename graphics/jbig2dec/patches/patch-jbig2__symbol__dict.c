$NetBSD: patch-jbig2__symbol__dict.c,v 1.1 2017/08/05 08:03:05 nros Exp $
* fix CVE-2017-7885 and CVE-2017-9216
  fixed upstream so remove this patch on the next version update
--- jbig2_symbol_dict.c.orig	2017-08-05 07:24:59.000000000 +0000
+++ jbig2_symbol_dict.c
@@ -499,8 +499,10 @@ jbig2_decode_symbol_dict(Jbig2Ctx *ctx,
                         }
 
                         /* multiple symbols are handled as a text region */
-                        jbig2_decode_text_region(ctx, segment, tparams, (const Jbig2SymbolDict * const *)refagg_dicts,
+                        code = jbig2_decode_text_region(ctx, segment, tparams, (const Jbig2SymbolDict * const *)refagg_dicts,
                                                  n_refagg_dicts, image, data, size, GR_stats, as, ws);
+                        if (code < 0)
+                            goto cleanup4;
 
                         SDNEWSYMS->glyphs[NSYMSDECODED] = image;
                         refagg_dicts[0]->glyphs[params->SDNUMINSYMS + NSYMSDECODED] = jbig2_image_clone(ctx, SDNEWSYMS->glyphs[NSYMSDECODED]);
@@ -633,7 +635,7 @@ jbig2_decode_symbol_dict(Jbig2Ctx *ctx,
                 byte *dst = image->data;
 
                 /* SumatraPDF: prevent read access violation */
-                if (size - jbig2_huffman_offset(hs) < image->height * stride) {
+                if ((size - jbig2_huffman_offset(hs) < image->height * stride) || (size < jbig2_huffman_offset(hs))) {
                     jbig2_error(ctx, JBIG2_SEVERITY_FATAL, segment->number, "not enough data for decoding (%d/%d)", image->height * stride,
                                 size - jbig2_huffman_offset(hs));
                     jbig2_image_release(ctx, image);
