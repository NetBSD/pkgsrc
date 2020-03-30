$NetBSD: patch-stubs.inc,v 1.1 2020/03/30 19:39:32 joerg Exp $

pcap_open no longer exists in NetBSD, so don't redefine pcap_rmtauth.
pcap_setsampling still has a prototype, but no implementation.

--- stubs.inc.orig	2020-03-29 03:00:42.548466448 +0000
+++ stubs.inc
@@ -354,11 +354,13 @@ int pcap_parsesrcstr(const char *source,
 #ifdef _MSC_VER
 #pragma message( "Warning: the function pcap_open() is not available" )
 #endif
+#ifndef HAVE_PCAP_OPEN_DEAD
 struct pcap_rmtauth {
     int type;
     char *username;
     char *password;
 };
+#endif
 
 pcap_t * pcap_open(const char *source, int snaplen, int flags, int read_timeout, struct pcap_rmtauth *auth, char *err);
 pcap_t * pcap_open(const char *source, int snaplen, int flags, int read_timeout, struct pcap_rmtauth *auth, char *err) {
@@ -516,10 +518,12 @@ HANDLE pcap_getevent(pcap_t *p) {
 #ifdef _MSC_VER
 #pragma message( "Warning: the function pcap_setsampling() is not available" )
 #endif
+#ifndef PCAP_SAMP_NOSAMP
 struct pcap_samp {
     int method;
     int value;
 };
+#endif
 
 struct pcap_samp *pcap_setsampling(pcap_t *p);
 struct pcap_samp *pcap_setsampling(pcap_t *p) {
