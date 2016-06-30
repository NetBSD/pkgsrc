$NetBSD: patch-src_inc_clrconfigvalues.h,v 1.1 2016/06/30 12:16:24 kamil Exp $

Revert:                                                         

commit 5ac6af932fe2a3f4b285b6dcc79010caf807ea9d
Author: Mike McLaughlin <mikem@microsoft.com>
Date:   Fri May 27 20:03:32 2016 -0700

    Fix the named semaphore leak on OSX (and Linux) (#5269)

It broke NetBSD.

--- src/inc/clrconfigvalues.h.orig	2016-06-14 01:12:15.000000000 +0000
+++ src/inc/clrconfigvalues.h
@@ -249,6 +249,7 @@ CONFIG_DWORD_INFO_DIRECT_ACCESS(INTERNAL
 CONFIG_DWORD_INFO_DIRECT_ACCESS(INTERNAL_DbgTransportLogClass, W("DbgTransportLogClass"), "mask to control what is logged in DbgTransportLog")
 RETAIL_CONFIG_STRING_INFO_EX(UNSUPPORTED_DbgTransportProxyAddress, W("DbgTransportProxyAddress"), "allows specifying the transport proxy address", CLRConfig::REGUTIL_default)
 CONFIG_DWORD_INFO_EX(INTERNAL_DbgTrapOnSkip, W("DbgTrapOnSkip"), 0, "allows breaking when we skip a breakpoint", CLRConfig::REGUTIL_default)
+RETAIL_CONFIG_DWORD_INFO(UNSUPPORTED_DbgWaitForDebuggerAttach, W("DbgWaitForDebuggerAttach"), 0, "Makes CoreCLR wait for a managed debugger to attach on process start (1) or regular process start (0)")
 CONFIG_DWORD_INFO_EX(INTERNAL_DbgWaitTimeout, W("DbgWaitTimeout"), 1, "specifies the timeout value for waits", CLRConfig::REGUTIL_default)
 RETAIL_CONFIG_DWORD_INFO_EX(UNSUPPORTED_DbgWFDETimeout, W("DbgWFDETimeout"), 25, "specifies the timeout value for wait when waiting for a debug event", CLRConfig::REGUTIL_default)
 CONFIG_DWORD_INFO_EX(INTERNAL_RaiseExceptionOnAssert, W("RaiseExceptionOnAssert"), 0, "Raise a first chance (if set to 1) or second chance (if set to 2) exception on asserts.", CLRConfig::REGUTIL_default)
