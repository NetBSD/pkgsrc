$NetBSD: patch-checkvm_checkvm.c,v 1.2 2013/11/11 16:42:38 joerg Exp $

--- checkvm/checkvm.c.orig	2012-12-25 19:48:10.000000000 +0000
+++ checkvm/checkvm.c
@@ -46,30 +46,6 @@ VM_EMBED_VERSION(CHECKVM_VERSION_STRING)
 #ifdef __GNUC__
 
 /*
- *  outl and inl: Output or input a 32-bit word
- */
-static __inline__ void
-outl(
-    const uint32 port,
-    uint32       val
-)
-{
-  __asm__ volatile("out%L0 (%%dx)" : :"a" (val), "d" (port));
-}
-
-static __inline__ uint32
-inl(
-    const uint32 port
-)
-{
-  uint32 ret;
-
-  __asm__ volatile("in%L0 (%%dx)" : "=a" (ret) : "d" (port));
-  return ret;
-}
-
-
-/*
  *  getVersion  -  Read VM version & product code through backdoor
  */
 void
@@ -77,7 +53,7 @@ getVersion(uint32 *version)
 {
    uint32 eax, ebx, ecx, edx;
    
-   __asm__ volatile("inl (%%dx)" :
+   __asm__ volatile("inl %%dx, %%eax" :
    	            "=a"(eax), "=c"(ecx), "=d"(edx), "=b"(ebx) :
 		    "0"(BDOOR_MAGIC), "1"(BDOOR_CMD_GETVERSION),
 		    "2"(BDOOR_PORT) : "memory");
@@ -94,7 +70,7 @@ getHWVersion(uint32 *hwVersion)
 {
    uint32 eax, ebx, ecx, edx;
    
-   __asm__ volatile("inl (%%dx)" :
+   __asm__ volatile("inl %%dx, %%eax" :
    	            "=a"(eax), "=c"(ecx), "=d"(edx), "=b"(ebx) :
 		    "0"(BDOOR_MAGIC), "1"(BDOOR_CMD_GETHWVERSION),
 		    "2"(BDOOR_PORT) : "memory");
@@ -110,7 +86,7 @@ getScreenSize(uint32 *screensize)
 {
    uint32 eax, ebx, ecx, edx;
    
-   __asm__ volatile("inl (%%dx)" :
+   __asm__ volatile("inl %%dx, %%eax" :
    		    "=a"(eax), "=c"(ecx), "=d"(edx), "=b"(ebx) :
 		    "0"(BDOOR_MAGIC), "1"(BDOOR_CMD_GETSCREENSIZE),
 		    "2"(BDOOR_PORT) : "memory");
