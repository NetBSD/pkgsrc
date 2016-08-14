$NetBSD: patch-src_freebsd_signal.h,v 1.1 2016/08/14 18:27:05 scole Exp $

Make FreeBSD version compile

--- src/freebsd/signal.h.orig	2008-02-04 23:11:38.000000000 -0500
+++ src/freebsd/signal.h	2016-04-17 13:25:40.000000000 -0400
@@ -42,8 +42,35 @@
 		int	sigval_int;
 		ptr64	sigval_ptr;
 	} si_value;
+
+  /* XXX copied from /usr/include/sys/signal.h since si_band
+   * is already #define'd there
+   */
+#if 0
 	long	si_band;
 	int	__spare__[7];
+#else
+	union   {
+	  struct {
+	    int     _trapno;/* machine specific trap code */
+	  } _fault;
+	  struct {
+	    int     _timerid;
+	    int     _overrun;
+	  } _timer;
+	  struct {
+	    int     _mqd;
+	  } _mesgq;
+	  struct {
+	    long    _band;          /* band event for SIGPOLL */
+	  } _poll;                        /* was this ever used ? */
+	  struct {
+	    long    __spare1__;
+	    int     __spare2__[7];
+	  } __spare__;
+	} _reason;
+#endif
+  
 };
 
 int signal_get_handler(int, struct sigaction64 *);
