$NetBSD: patch-lgi_ffi.lua,v 1.2 2026/06/07 13:01:30 wiz Exp $

Wrap gi.require with assert in class.lua and ffi.lua
https://github.com/lgi-devs/lgi/commit/5233d837046988296b1b442ecb269b4be91e0b7f

ffi: Adapt load_enum to glib 2.87 changes
https://github.com/lgi-devs/lgi/pull/352

--- lgi/ffi.lua.orig	2026-06-07 12:58:57.471269587 +0000
+++ lgi/ffi.lua
@@ -21,8 +21,8 @@ local ffi = {}
 
 local ffi = {}
 
-local gobject = gi.require('GObject')
-local glib = gi.require('GLib')
+local gobject = assert(gi.require('GObject'))
+local glib = assert(gi.require('GLib'))
 
 -- Gather all basic types.  We have to 'steal' them from well-known
 -- declarations, because girepository API does not allow synthesizing
@@ -76,16 +76,22 @@ function ffi.load_enum(gtype, name)
 
 -- Creates new enum/flags table with all values from specified gtype.
 function ffi.load_enum(gtype, name)
-   local GObject = core.repo.GObject
+   local GLib, GObject = core.repo.GLib, core.repo.GObject
    local is_flags = GObject.Type.is_a(gtype, GObject.Type.FLAGS)
    local enum_component = component.create(
       gtype, is_flags and enum.bitflags_mt or enum.enum_mt, name)
    local type_class = GObject.TypeClass.ref(gtype)
    local enum_class = core.record.cast(
       type_class, is_flags and GObject.FlagsClass or GObject.EnumClass)
-   for i = 0, enum_class.n_values - 1 do
-      local val = core.record.fromarray(enum_class.values, i)
-      enum_component[core.upcase(val.value_nick):gsub('%-', '_')] = val.value
+   if GLib.check_version(2, 87, 0) then
+      for i = 0, enum_class.n_values - 1 do
+         local val = core.record.fromarray(enum_class.values, i)
+         enum_component[core.upcase(val.value_nick):gsub('%-', '_')] = val.value
+      end
+   else
+      for _, val in ipairs(enum_class.values) do
+         enum_component[core.upcase(val.value_nick):gsub('%-', '_')] = val.value
+      end
    end
    type_class:unref()
    return enum_component
