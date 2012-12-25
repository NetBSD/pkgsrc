$NetBSD: patch-checkvm_checkvm.c,v 1.1 2012/12/25 21:02:15 joerg Exp $

--- checkvm/checkvm.c.orig	2012-12-25 19:48:10.000000000 +0000
+++ checkvm/checkvm.c
@@ -77,7 +77,7 @@ getVersion(uint32 *version)
 {
    uint32 eax, ebx, ecx, edx;
    
-   __asm__ volatile("inl (%%dx)" :
+   __asm__ volatile("inl %%dx, %%eax" :
    	            "=a"(eax), "=c"(ecx), "=d"(edx), "=b"(ebx) :
 		    "0"(BDOOR_MAGIC), "1"(BDOOR_CMD_GETVERSION),
 		    "2"(BDOOR_PORT) : "memory");
@@ -94,7 +94,7 @@ getHWVersion(uint32 *hwVersion)
 {
    uint32 eax, ebx, ecx, edx;
    
-   __asm__ volatile("inl (%%dx)" :
+   __asm__ volatile("inl %%dx, %%eax" :
    	            "=a"(eax), "=c"(ecx), "=d"(edx), "=b"(ebx) :
 		    "0"(BDOOR_MAGIC), "1"(BDOOR_CMD_GETHWVERSION),
 		    "2"(BDOOR_PORT) : "memory");
@@ -110,7 +110,7 @@ getScreenSize(uint32 *screensize)
 {
    uint32 eax, ebx, ecx, edx;
    
-   __asm__ volatile("inl (%%dx)" :
+   __asm__ volatile("inl %%dx, %%eax" :
    		    "=a"(eax), "=c"(ecx), "=d"(edx), "=b"(ebx) :
 		    "0"(BDOOR_MAGIC), "1"(BDOOR_CMD_GETSCREENSIZE),
 		    "2"(BDOOR_PORT) : "memory");
