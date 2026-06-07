$NetBSD: patch-lgi_class.lua,v 1.1 2026/06/07 13:01:30 wiz Exp $

Wrap gi.require with assert in class.lua and ffi.lua
https://github.com/lgi-devs/lgi/commit/5233d837046988296b1b442ecb269b4be91e0b7f

--- lgi/class.lua.orig	2017-10-09 18:55:55.000000000 +0000
+++ lgi/class.lua
@@ -20,7 +20,7 @@ local ti = ffi.types
 local record = require 'lgi.record'
 local ffi = require 'lgi.ffi'
 local ti = ffi.types
-local GObject = gi.require 'GObject'
+local GObject = assert(gi.require('GObject'))
 
 -- Implementation of class and interface component loading.
 local class = {
