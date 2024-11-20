$NetBSD: patch-mDNSShared_dnssd__clientstub.c,v 1.2 2024/11/20 17:56:21 hauke Exp $

Quality Code Pasto

--- mDNSShared/dnssd_clientstub.c.orig	2024-11-19 18:13:39.474891771 +0000
+++ mDNSShared/dnssd_clientstub.c
@@ -2023,6 +2023,8 @@ DNSServiceErrorType DNSServiceRegisterIn
     DNSServiceErrorType err;
     union { uint16_t s; u_char b[2]; } port = { portInNetworkByteOrder };
     (void)attr;
+    const uint8_t *limit;
+
 
     if (!sdRef || !regtype) return kDNSServiceErr_BadParam;
     if (!name) name = "";
@@ -2054,6 +2056,7 @@ DNSServiceErrorType DNSServiceRegisterIn
     if (!hdr) { DNSServiceRefDeallocate(*sdRef); *sdRef = NULL; return kDNSServiceErr_NoMemory; }
     if (!callBack) hdr->ipc_flags |= IPC_FLAGS_NOREPLY;
 
+    limit = ptr + len;
     put_flags(flags, &ptr);
     put_uint32(interfaceIndex, &ptr);
     put_string(name, &ptr);
@@ -2335,6 +2338,7 @@ DNSServiceErrorType DNSServiceRegisterRe
     DNSRecordRef rref = NULL;
     DNSRecord **p;
     (void)attr;
+    const uint8_t *limit;
 
     // Verify that only one of the following flags is set.
     int f1 = (flags & kDNSServiceFlagsShared) != 0;
@@ -2389,6 +2393,7 @@ DNSServiceErrorType DNSServiceRegisterRe
     hdr = create_hdr(reg_record_request, &len, &ptr, !(flags & kDNSServiceFlagsQueueRequest), sdRef);
     if (!hdr) return kDNSServiceErr_NoMemory;
 
+    limit = ptr + len;
     put_flags(flags, &ptr);
     put_uint32(interfaceIndex, &ptr);
     put_string(fullname, &ptr);
