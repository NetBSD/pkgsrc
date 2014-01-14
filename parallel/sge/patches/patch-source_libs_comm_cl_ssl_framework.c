$NetBSD: patch-source_libs_comm_cl_ssl_framework.c,v 1.1 2014/01/14 10:21:39 markd Exp $

Fix typo

--- source/libs/comm/cl_ssl_framework.c.orig	2013-10-28 16:22:53.000000000 +0000
+++ source/libs/comm/cl_ssl_framework.c
@@ -3637,7 +3637,7 @@ int cl_com_ssl_connection_request_handle
 
 #ifndef USE_POLL
    if (sockfd >= FD_SETSIZE) {
-       CL_LOG_int(CL_LOG_ERROR,"number of filedescriptors exceeds FD_SETSIZE of this system: ", FD_SETSIZE);
+       CL_LOG_INT(CL_LOG_ERROR,"number of filedescriptors exceeds FD_SETSIZE of this system: ", FD_SETSIZE);
        shutdown(sockfd, 2);
        close(sockfd);
        cl_commlib_push_application_error(CL_LOG_ERROR, CL_RETVAL_REACHED_FILEDESCRIPTOR_LIMIT, MSG_CL_COMMLIB_COMPILE_SOURCE_WITH_LARGER_FD_SETSIZE );
