$NetBSD: patch-plugins_video_H.263-1998_h263-1993.cxx,v 1.2 2013/01/19 20:29:24 riastradh Exp $

--- plugins/video/H.263-1998/h263-1998.cxx.orig	2009-09-22 00:57:52.000000000 +0000
+++ plugins/video/H.263-1998/h263-1998.cxx
@@ -364,9 +364,6 @@ void H263_Base_EncoderContext::SetTSTO (
   _context->qmax = round ( (31.0 - H263P_MIN_QUANT) / 31.0 * tsto + H263P_MIN_QUANT);
   _context->qmax = std::min( _context->qmax, 31);
 
-  _context->mb_qmin = _context->qmin;
-  _context->mb_qmax = _context->qmax;
-
   // Lagrange multipliers - this is how the context defaults do it:
   _context->lmin = _context->qmin * FF_QP2LAMBDA;
   _context->lmax = _context->qmax * FF_QP2LAMBDA; 
@@ -478,8 +475,6 @@ bool H263_Base_EncoderContext::OpenCodec
   CODEC_TRACER(tracer, "GOP is " << _context->gop_size);
   CODEC_TRACER(tracer, "qmin set to " << _context->qmin);
   CODEC_TRACER(tracer, "qmax set to " << _context->qmax);
-  CODEC_TRACER(tracer, "mb_qmin set to " << _context->mb_qmin);
-  CODEC_TRACER(tracer, "mb_qmax set to " << _context->mb_qmax);
   CODEC_TRACER(tracer, "bit_rate set to " << _context->bit_rate);
   CODEC_TRACER(tracer, "bit_rate_tolerance set to " <<_context->bit_rate_tolerance);
   CODEC_TRACER(tracer, "rc_min_rate set to " << _context->rc_min_rate);
@@ -688,7 +683,7 @@ int H263_RFC2190_EncoderContext::EncodeF
 
   _inputFrame->data[1] = _inputFrame->data[0] + size;
   _inputFrame->data[2] = _inputFrame->data[1] + (size / 4);
-  _inputFrame->pict_type = (flags && forceIFrame) ? FF_I_TYPE : 0;
+  _inputFrame->pict_type = (flags && forceIFrame) ? AV_PICTURE_TYPE_I : AV_PICTURE_TYPE_NONE;
 
   currentMb = 0;
   currentBytes = 0;
@@ -885,7 +880,7 @@ int H263_RFC2429_EncoderContext::EncodeF
   _inputFrame->data[0] = _inputFrameBuffer + FF_INPUT_BUFFER_PADDING_SIZE;
   _inputFrame->data[1] = _inputFrame->data[0] + size;
   _inputFrame->data[2] = _inputFrame->data[1] + (size / 4);
-  _inputFrame->pict_type = (flags && forceIFrame) ? FF_I_TYPE : 0;
+  _inputFrame->pict_type = (flags && forceIFrame) ? AV_PICTURE_TYPE_I : AV_PICTURE_TYPE_NONE;
  
   _txH263PFrame->BeginNewFrame();
   _txH263PFrame->SetTimestamp(srcRTP.GetTimestamp());
