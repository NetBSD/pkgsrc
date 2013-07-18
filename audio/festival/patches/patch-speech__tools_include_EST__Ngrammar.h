$NetBSD: patch-speech__tools_include_EST__Ngrammar.h,v 1.2 2013/07/18 20:19:51 joerg Exp $

--- speech_tools/include/EST_Ngrammar.h.orig	2013-07-17 14:46:59.000000000 +0000
+++ speech_tools/include/EST_Ngrammar.h
@@ -538,18 +538,18 @@ public:
 						     double floor);
     friend EST_write_status save_ngram_htk_ascii(const EST_String filename, 
 						 EST_Ngrammar &n,
-						 double floor=0.0);
+						 double floor);
 
     //friend EST_write_status save_ngram_htk_binary(const EST_String filename, 
     //					  EST_Ngrammar &n);
     friend EST_write_status save_ngram_cstr_ascii(const EST_String filename, 
 						  EST_Ngrammar &n,
-						  const bool trace=false,
-						  double floor=0.0);
+						  const bool trace,
+						  double floor);
     friend EST_write_status save_ngram_cstr_bin(const EST_String filename, 
 						EST_Ngrammar &n, 
-						const bool trace=false,
-						double floor=0.0);
+						const bool trace,
+						double floor);
     friend EST_write_status save_ngram_arpa(const EST_String filename, 
 					    EST_Ngrammar &n);
     friend EST_write_status save_ngram_arpa_sub(ostream *ost, 
@@ -561,11 +561,11 @@ public:
     // Auxiliary functions
     
     // smoothing
-friend void frequency_of_frequencies(EST_DVector &ff, EST_Ngrammar &n,int this_order=0);
-friend void map_frequencies(EST_Ngrammar &n, const EST_DVector &map, const int this_order=0);
-friend bool Good_Turing_smooth(EST_Ngrammar &n, int maxcount, int mincount=0);
+friend void frequency_of_frequencies(EST_DVector &ff, EST_Ngrammar &n,int this_order);
+friend void map_frequencies(EST_Ngrammar &n, const EST_DVector &map, const int this_order);
+friend bool Good_Turing_smooth(EST_Ngrammar &n, int maxcount, int mincount);
 friend void Good_Turing_discount(EST_Ngrammar &ngrammar, const int maxcount,
-				 const double default_discount=0.5);
+				 const double default_discount);
 
 friend void fs_build_backoff_ngrams(EST_Ngrammar *backoff_ngrams,
 				    EST_Ngrammar &ngram);
@@ -584,6 +584,12 @@ friend class EST_BackoffNgrammar;
     
 };
 
+void frequency_of_frequencies(EST_DVector &ff, EST_Ngrammar &n,int this_order=0);
+void map_frequencies(EST_Ngrammar &n, const EST_DVector &map, const int this_order=0);
+bool Good_Turing_smooth(EST_Ngrammar &n, int maxcount, int mincount=0);
+void Good_Turing_discount(EST_Ngrammar &ngrammar, const int maxcount,
+				 const double default_discount=0.5);
+
 void Ngram_freqsmooth(EST_Ngrammar &ngram,
 		      int smooth_thresh1,
 		      int smooth_thresh2);
