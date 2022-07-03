$NetBSD: patch-common_utils.hpp,v 1.1 2022/07/03 16:09:15 nia Exp $

Add NetBSD support.

--- common/utils.hpp.orig	2021-12-22 17:40:36.000000000 +0000
+++ common/utils.hpp
@@ -1,5 +1,4 @@
-/***
-    This file is part of snapcast
+/*** This file is part of snapcast
     Copyright (C) 2014-2020  Johannes Pohl
 
     This program is free software: you can redistribute it and/or modify
@@ -44,7 +43,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <vector>
-#if !defined(WINDOWS) && !defined(FREEBSD)
+#if defined(MACOS) || defined(__linux__)
 #include <sys/sysinfo.h>
 #endif
 #ifdef MACOS
@@ -53,6 +52,10 @@
 #include <ifaddrs.h>
 #include <net/if_dl.h>
 #endif
+#ifdef __NetBSD__
+#include <ifaddrs.h>
+#include <net/if_dl.h>
+#endif
 #ifdef ANDROID
 #include <sys/system_properties.h>
 #endif
@@ -306,7 +309,7 @@ static std::string getMacAddress(int soc
         {
             if (!(ifr.ifr_flags & IFF_LOOPBACK)) // don't count loopback
             {
-#ifdef MACOS
+#if defined(MACOS) || defined(__NetBSD__)
                 /// Dirty Mac version
                 struct ifaddrs *ifap, *ifaptr;
                 unsigned char* ptr;
@@ -333,6 +336,7 @@ static std::string getMacAddress(int soc
                 }
 #endif
 
+#ifndef __NetBSD__
 #ifdef FREEBSD
                 if (ioctl(sock, SIOCGIFMAC, &ifr) == 0)
 #else
@@ -355,6 +359,7 @@ static std::string getMacAddress(int soc
                             return line;
                     }
                 }
+#endif
             }
         }
         else
@@ -369,7 +374,7 @@ static std::string getMacAddress(int soc
         return "";
 
     char mac[19];
-#ifndef FREEBSD
+#if !defined(FREEBSD) && !defined(__NetBSD__)
     sprintf(mac, "%02x:%02x:%02x:%02x:%02x:%02x", (unsigned char)ifr.ifr_hwaddr.sa_data[0], (unsigned char)ifr.ifr_hwaddr.sa_data[1],
             (unsigned char)ifr.ifr_hwaddr.sa_data[2], (unsigned char)ifr.ifr_hwaddr.sa_data[3], (unsigned char)ifr.ifr_hwaddr.sa_data[4],
             (unsigned char)ifr.ifr_hwaddr.sa_data[5]);
