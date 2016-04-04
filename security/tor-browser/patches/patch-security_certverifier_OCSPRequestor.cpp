$NetBSD: patch-security_certverifier_OCSPRequestor.cpp,v 1.1 2016/04/04 17:36:34 joerg Exp $

--- security/certverifier/OCSPRequestor.cpp.orig	2016-04-04 15:32:34.076128034 +0000
+++ security/certverifier/OCSPRequestor.cpp
@@ -174,7 +174,6 @@ DoOCSPRequest(PLArenaPool* arena, const 
   SEC_HTTP_REQUEST_SESSION requestSessionPtr;
   if (nsNSSHttpInterface::createFcn(serverSession.get(), "http",
                                     path.get(), method.get(),
-                                    isolationKey,
                                     timeout, &requestSessionPtr)
         != SECSuccess) {
     PR_SetError(SEC_ERROR_NO_MEMORY, 0);
