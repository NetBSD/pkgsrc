$NetBSD: patch-src_rig-data.h,v 1.1 2021/03/09 08:14:01 nia Exp $

Description: align affected parts for Hamlib4.0
Author: Ervin Hegedus <airween@gmail.com>
From Debian:
https://sources.debian.org/data/main/g/grig/0.8.1-3/debian/patches/04-hamlib-align.patch

--- src/rig-data.h.orig	2008-12-15 01:14:50.000000000 +0000
+++ src/rig-data.h
@@ -190,7 +190,7 @@ typedef struct {
 
 #define GRIG_LEVEL_RD (RIG_LEVEL_RFPOWER | RIG_LEVEL_AGC | RIG_LEVEL_SWR | RIG_LEVEL_ALC | \
                        RIG_LEVEL_STRENGTH | RIG_LEVEL_ATT | RIG_LEVEL_PREAMP | \
-                       RIG_LEVEL_VOX | RIG_LEVEL_AF | RIG_LEVEL_RF | RIG_LEVEL_SQL | \
+                       RIG_LEVEL_VOXDELAY | RIG_LEVEL_AF | RIG_LEVEL_RF | RIG_LEVEL_SQL | \
                        RIG_LEVEL_IF | RIG_LEVEL_APF | RIG_LEVEL_NR | RIG_LEVEL_PBT_IN | \
                        RIG_LEVEL_PBT_OUT | RIG_LEVEL_CWPITCH |          \
                        RIG_LEVEL_MICGAIN | RIG_LEVEL_KEYSPD | RIG_LEVEL_NOTCHF | \
@@ -198,7 +198,7 @@ typedef struct {
                        RIG_LEVEL_VOXGAIN | RIG_LEVEL_ANTIVOX)
 
 #define GRIG_LEVEL_WR (RIG_LEVEL_RFPOWER | RIG_LEVEL_AGC | RIG_LEVEL_ATT | RIG_LEVEL_PREAMP | \
-                       RIG_LEVEL_VOX | RIG_LEVEL_AF | RIG_LEVEL_RF | RIG_LEVEL_SQL | \
+                       RIG_LEVEL_VOXDELAY | RIG_LEVEL_AF | RIG_LEVEL_RF | RIG_LEVEL_SQL | \
                        RIG_LEVEL_IF | RIG_LEVEL_APF | RIG_LEVEL_NR | RIG_LEVEL_PBT_IN | \
                        RIG_LEVEL_PBT_OUT | RIG_LEVEL_CWPITCH |          \
                        RIG_LEVEL_MICGAIN | RIG_LEVEL_KEYSPD | RIG_LEVEL_NOTCHF | \
