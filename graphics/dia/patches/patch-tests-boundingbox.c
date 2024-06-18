$NetBSD: patch-tests-boundingbox.c,v 1.1 2024/06/18 09:07:25 markd Exp $

From caddfcab250fe677ecf294fad835b71e6b10cf26 Mon Sep 17 00:00:00 2001
From: Hans Breuer <hans@breuer.org>
Date: Fri, 3 Oct 2014 22:26:36 +0200
Subject: [PATCH] [warningectomy] incompatible pointer types passing ...

test-boundingbox.c:152:58: warning: incompatible pointer types passing 'void (const struct _TestBeziers *)' to parameter of type 'GTestDataFunc' (aka 'void (*)(gconstpointer)') [-Wincompatible-pointer-types]
      g_test_add_data_func (testpath, &_test_beziers[i], _check_one_bezier);
                                                         ^~~~~~~~~~~~~~~~~

diff --git a/tests/test-boundingbox.c b/tests/test-boundingbox.c
index f5b57250e..f542e590d 100644
--- tests/test-boundingbox.c
+++ tests/test-boundingbox.c
@@ -132,8 +132,9 @@ static struct _TestBeziers {
 #undef BEZ
 
 static void
-_check_one_bezier (const struct _TestBeziers *test)
+_check_one_bezier (gconstpointer p)
 {
+  const struct _TestBeziers *test = p;
   Rectangle rect;
   PolyBBExtras extra = {0, T*.7, T*.7, T*.7, 0 };
   
