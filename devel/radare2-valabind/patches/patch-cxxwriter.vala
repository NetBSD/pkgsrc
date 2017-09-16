$NetBSD: patch-cxxwriter.vala,v 1.1 2017/09/16 13:06:48 tnn Exp $

From f23ff9421c1875d18b1e558596557009b45faa19 Mon Sep 17 00:00:00 2001
From: pancake <pancake@nopcode.org>
Date: Thu, 9 Feb 2017 10:21:16 +0100
Subject: [PATCH] Fix build for Vala-git (future 0.36)

---
 cxxwriter.vala   | 2 +-
 dlangwriter.vala | 2 +-
 2 files changed, 2 insertions(+), 2 deletions(-)

--- cxxwriter.vala.orig	2016-01-20 03:13:50.000000000 +0000
+++ cxxwriter.vala
@@ -157,7 +157,7 @@ public class CxxWriter : ValabindWriter 
 	}
 
 	public void walk_field (Field f) {
-		if (f.get_ctype () == null) {
+		if (f.get_attribute_string ("CCode", "type") == null) {
 			//warning (
 			//	"Cannot resolve type for field '%s'".printf (f.get_cname ()));
 		} else {
