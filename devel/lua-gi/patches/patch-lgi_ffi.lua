$NetBSD: patch-lgi_ffi.lua,v 1.1 2026/04/20 06:24:41 wiz Exp $

ffi: Adapt load_enum to glib 2.87 changes
https://github.com/lgi-devs/lgi/pull/352

--- lgi/ffi.lua.orig	2017-10-09 18:55:55.000000000 +0000
+++ lgi/ffi.lua
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
