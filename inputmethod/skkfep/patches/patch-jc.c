$NetBSD: patch-jc.c,v 1.1 2012/12/20 21:50:47 joerg Exp $

--- jc.c.orig	2012-12-20 14:34:34.000000000 +0000
+++ jc.c
@@ -105,6 +105,8 @@ ConvRoutine ToSJ[] = {
 	{'P',cConvPS,"",""},
 };
 
+static void conv(char *is, char *os, char fc, char tc);
+
 FILE	*file_open(),*popen();
 
 main(argc,argv)
@@ -232,8 +234,7 @@ char	**argv,fromCode,toCode;
 	}
 }
 
-conv(is,os,fc,tc)
-char	*is,*os,fc,tc;
+static void conv(char *is, char *os, char fc, char tc)
 {	static uchar	mbuf[BF_SIZ];
 	int		i;
 
