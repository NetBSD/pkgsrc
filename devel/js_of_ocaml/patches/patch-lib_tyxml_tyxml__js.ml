$NetBSD: patch-lib_tyxml_tyxml__js.ml,v 1.1 2018/11/29 11:59:21 jaapb Exp $

Compile with tyxml 4.3.0 (patch from upstream)
--- lib/tyxml/tyxml_js.ml.orig	2018-07-26 14:06:06.000000000 +0000
+++ lib/tyxml/tyxml_js.ml
@@ -46,10 +46,12 @@ module Xml = struct
   type event_handler = Dom_html.event Js.t -> bool
   type mouse_event_handler = Dom_html.mouseEvent Js.t -> bool
   type keyboard_event_handler = Dom_html.keyboardEvent Js.t -> bool
+  type touch_event_handler = Dom_html.touchEvent Js.t -> bool
   type attrib_k =
     | Event of event_handler
     | MouseEvent of mouse_event_handler
     | KeyboardEvent of keyboard_event_handler
+    | TouchEvent of touch_event_handler
     | Attr of Js.js_string Js.t option React.S.t
   type attrib = aname * attrib_k
 
@@ -63,6 +65,7 @@ module Xml = struct
   let event_handler_attrib name (value : event_handler) = name,Event value
   let mouse_event_handler_attrib name (value : mouse_event_handler) = name,MouseEvent value
   let keyboard_event_handler_attrib name (value : keyboard_event_handler) = name,KeyboardEvent value
+  let touch_event_handler_attrib name (value : touch_event_handler) = name,TouchEvent value
   let uri_attrib name value = attr name (Js.string value)
   let uris_attrib name values = attr name (Js.string (String.concat " " values))
 
@@ -120,6 +123,7 @@ module Xml = struct
         | Event h -> Js.Unsafe.set node n (fun ev -> Js.bool (h ev))
         | MouseEvent h -> Js.Unsafe.set node n (fun ev -> Js.bool (h ev))
         | KeyboardEvent h -> Js.Unsafe.set node n (fun ev -> Js.bool (h ev))
+        | TouchEvent h -> Js.Unsafe.set node n (fun ev -> Js.bool (h ev))
       ) l
 
   let leaf ?(a=[]) name =
@@ -286,7 +290,8 @@ module R = struct
     match a with
     | Xml.Event _
     | Xml.MouseEvent _
-    | Xml.KeyboardEvent _ ->
+    | Xml.KeyboardEvent _
+    | Xml.TouchEvent _ -> 
       raise (Invalid_argument "filter_attrib not implemented for event handler")
     | Xml.Attr a ->
       name,
@@ -307,6 +312,7 @@ module R = struct
     type event_handler = Xml.event_handler
     type mouse_event_handler = Xml.mouse_event_handler
     type keyboard_event_handler = Xml.keyboard_event_handler
+    type touch_event_handler = Xml.touch_event_handler
     type attrib = Xml.attrib
 
     let attr name f s =
@@ -321,6 +327,7 @@ module R = struct
     let event_handler_attrib name s = Xml.event_handler_attrib name s
     let mouse_event_handler_attrib name s = Xml.mouse_event_handler_attrib name s
     let keyboard_event_handler_attrib name s = Xml.keyboard_event_handler_attrib name s
+    let touch_event_handler_attrib name s = Xml.touch_event_handler_attrib name s
     let uri_attrib name s = attr name (fun f -> Some (Js.string f)) s
     let uris_attrib name s = attr name (fun f -> Some (Js.string (String.concat " " f))) s
 
