$NetBSD: patch-src_PollVec.cc,v 1.1 2017/09/14 06:38:21 adam Exp $

Fix compiler errors.

--- src/PollVec.cc.orig	2017-09-14 06:28:06.000000000 +0000
+++ src/PollVec.cc
@@ -30,7 +30,7 @@ static inline bool operator<(const timev
 
 void PollVec::AddTimeoutU(unsigned t)
 {
-   struct timeval new_timeout={t/1000000,t%1000000};
+   struct timeval new_timeout={(int)t/1000000,(int)t%1000000};
    if(tv_timeout.tv_sec<0 || new_timeout<tv_timeout)
       SetTimeout(new_timeout);
 }
