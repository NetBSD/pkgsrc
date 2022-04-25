$NetBSD: patch-src_kmers.cc,v 1.1 2022/04/25 14:34:06 tnn Exp $

avoid ambiguous math functions

--- src/kmers.cc.orig	2021-06-08 21:08:14.000000000 +0000
+++ src/kmers.cc
@@ -23,6 +23,9 @@
 //
 #include "kmers.h"
 
+using std::floor;
+using std::pow;
+
 int determine_kmer_length(int read_len, int dist) {
     int kmer_len, span, min_matches;
 
