$NetBSD: patch-scripts_audio_wavread.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/audio/wavread.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/audio/wavread.m
@@ -18,21 +18,26 @@
 
 ## -*- texinfo -*-
 ## @deftypefn {Function File} {@var{y} =} wavread (@var{filename})
+## @deftypefnx {Function File} {[@var{y}, @var{Fs}, @var{bps}] =} wavread (@var{filename})
+## @deftypefnx {Function File} {[@dots{}] =} wavread (@var{filename}, @var{n})
+## @deftypefnx {Function File} {[@dots{}] =} wavread (@var{filename}, @var{n1} @var{n2})
+## @deftypefnx {Function File} {[@var{samples}, @var{channels}] =} wavread (@var{filename}, "size")
+## 
 ## Load the RIFF/WAVE sound file @var{filename}, and return the samples
 ## in vector @var{y}.  If the file contains multichannel data, then
 ## @var{y} is a matrix with the channels represented as columns.
 ##
-## @deftypefnx {Function File} {[@var{y}, @var{Fs}, @var{bps}] =} wavread (@var{filename})
+## @code{[@var{y}, @var{Fs}, @var{bps}] = wavread (@var{filename})}
 ## Additionally return the sample rate (@var{fs}) in Hz and the number of bits
 ## per sample (@var{bps}).
 ##
-## @deftypefnx {Function File} {[@dots{}] =} wavread (@var{filename}, @var{n})
+## @code{[@dots{}] = wavread (@var{filename}, @var{n})}
 ## Read only the first @var{n} samples from each channel.
 ##
-## @deftypefnx {Function File} {[@dots{}] =} wavread (@var{filename}, @var{n1} @var{n2})
+## @code{wavread (@var{filename}, @var{n1} @var{n2})}
 ## Read only samples @var{n1} through @var{n2} from each channel.
 ##
-## @deftypefnx {Function File} {[@var{samples}, @var{channels}] =} wavread (@var{filename}, "size")
+## @code{[@var{samples}, @var{channels}] = wavread (@var{filename}, "size")}
 ## Return the number of samples (@var{n}) and channels (@var{ch})
 ## instead of the audio data.
 ## @seealso{wavwrite}
