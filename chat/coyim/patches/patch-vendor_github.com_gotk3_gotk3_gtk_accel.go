$NetBSD: patch-vendor_github.com_gotk3_gotk3_gtk_accel.go,v 1.2 2021/04/07 19:04:22 fox Exp $

Solve GtkAccelKey issue with golang 1.16.

https://github.com/gotk3/gotk3/pull/730

--- vendor/github.com/gotk3/gotk3/gtk/accel.go.orig	2021-04-07 18:37:25.213428101 +0000
+++ vendor/github.com/gotk3/gotk3/gtk/accel.go
@@ -69,6 +69,20 @@ func AcceleratorSetDefaultModMask(mods g
 }
 
 /*
+ * GtkAccelLabel
+ */
+
+// TODO:
+// gtk_accel_label_new().
+// gtk_accel_label_set_accel_closure().
+// gtk_accel_label_get_accel_widget().
+// gtk_accel_label_set_accel_widget().
+// gtk_accel_label_get_accel_width().
+// gtk_accel_label_set_accel(). since GTK 3.6
+// gtk_accel_label_get_accel(). since GTK 3.12
+// gtk_accel_label_refetch().
+
+/*
  * GtkAccelGroup
  */
 
@@ -93,6 +107,10 @@ func marshalAccelGroup(p uintptr) (inter
 }
 
 func wrapAccelGroup(obj *glib.Object) *AccelGroup {
+	if obj == nil {
+		return nil
+	}
+
 	return &AccelGroup{obj}
 }
 
@@ -191,6 +209,9 @@ func AccelGroupsFromObject(obj *glib.Obj
 	if res == nil {
 		return nil
 	}
+
+	// TODO: call DataWrapper on SList and wrap them to gtk.AccelGroup
+
 	return (*glib.SList)(unsafe.Pointer(res))
 }
 
@@ -219,6 +240,10 @@ func marshalAccelMap(p uintptr) (interfa
 }
 
 func wrapAccelMap(obj *glib.Object) *AccelMap {
+	if obj == nil {
+		return nil
+	}
+
 	return &AccelMap{obj}
 }
 
@@ -230,32 +255,13 @@ func AccelMapAddEntry(path string, key u
 	C.gtk_accel_map_add_entry((*C.gchar)(cstr), C.guint(key), C.GdkModifierType(mods))
 }
 
-type AccelKey struct {
-	key   uint
-	mods  gdk.ModifierType
-	flags uint16
-}
+type AccelKey C.GtkAccelKey
 
-func (v *AccelKey) native() *C.struct__GtkAccelKey {
+func (v *AccelKey) native() *C.GtkAccelKey {
 	if v == nil {
 		return nil
 	}
-
-	var val C.struct__GtkAccelKey
-	val.accel_key = C.guint(v.key)
-	val.accel_mods = C.GdkModifierType(v.mods)
-	val.accel_flags = v.flags
-	return &val
-}
-
-func wrapAccelKey(obj *C.struct__GtkAccelKey) *AccelKey {
-	var v AccelKey
-
-	v.key = uint(obj.accel_key)
-	v.mods = gdk.ModifierType(obj.accel_mods)
-	v.flags = uint16(obj.accel_flags)
-
-	return &v
+	return (*C.GtkAccelKey)(v)
 }
 
 // AccelMapLookupEntry is a wrapper around gtk_accel_map_lookup_entry().
@@ -263,10 +269,10 @@ func AccelMapLookupEntry(path string) *A
 	cstr := C.CString(path)
 	defer C.free(unsafe.Pointer(cstr))
 
-	var v *C.struct__GtkAccelKey
+	var v = new(AccelKey)
 
-	C.gtk_accel_map_lookup_entry((*C.gchar)(cstr), v)
-	return wrapAccelKey(v)
+	C.gtk_accel_map_lookup_entry((*C.gchar)(cstr), v.native())
+	return v
 }
 
 // AccelMapChangeEntry is a wrapper around gtk_accel_map_change_entry().
@@ -417,7 +423,7 @@ func (v *Window) AddAccelGroup(accelGrou
 	C.gtk_window_add_accel_group(v.native(), accelGroup.native())
 }
 
-// RemoveAccelGroup() is a wrapper around gtk_window_add_accel_group().
+// RemoveAccelGroup() is a wrapper around gtk_window_remove_accel_group().
 func (v *Window) RemoveAccelGroup(accelGroup *AccelGroup) {
 	C.gtk_window_remove_accel_group(v.native(), accelGroup.native())
 }
@@ -432,4 +438,10 @@ func (v *Window) RemoveAccelGroup(accelG
 // TODO: gtk_accel_map_foreach  - can't be done without a function type
 
 // TODO: gtk_accel_map_load_scanner
-// TODO: gtk_widget_list_accel_closures
+
+/*
+ * GtkWidget
+ */
+
+// TODO:
+// gtk_widget_list_accel_closures
