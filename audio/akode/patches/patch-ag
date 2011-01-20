$NetBSD: patch-ag,v 1.2 2011/01/20 11:48:18 markd Exp $

* Attempt fallback to ffmpeg decoder if loading the "native" one fails.
* Reset resampler/converter if it isn't necessary any more.

--- akode/lib/player.cpp.orig	2009-02-20 15:04:49 +0200
+++ akode/lib/player.cpp	2009-02-20 15:11:55 +0200
@@ -37,6 +37,7 @@
 
 #include "player.h"
 
+#include <cstring>
 #ifndef NDEBUG
 #include <iostream>
 #define AKODE_DEBUG(x) {std::cerr << "akode: " << x << "\n";}
@@ -345,8 +345,11 @@ bool Player::load() {
             d->src = 0;
             return false;
         }
-        if (!d->decoder_handler.load(format))
+        if (!d->decoder_handler.load(format)) {
             AKODE_DEBUG("Could not load " << format << "-decoder");
+            if (!d->decoder_handler.load("ffmpeg"))
+                AKODE_DEBUG("Could not load ffmpeg-decoder");
+        }
     }
 
     if (!d->decoder_handler.isLoaded()) {
@@ -398,6 +401,9 @@ bool Player::load() {
         if (d->sample_rate != first_frame.sample_rate) {
             AKODE_DEBUG("Resampling to " << d->sample_rate);
             d->resampler->setSampleRate(d->sample_rate);
+        } else {
+            delete d->resampler;
+            d->resampler = 0;
         }
         int out_channels = d->sink->audioConfiguration()->channels;
         int in_channels = first_frame.channels;
@@ -419,6 +425,9 @@ bool Player::load() {
                 d->converter = new Converter(out_width);
             else
                 d->converter->setSampleWidth(out_width);
+        } else {
+            delete d->converter;
+            d->converter = 0;
         }
     }
     else
