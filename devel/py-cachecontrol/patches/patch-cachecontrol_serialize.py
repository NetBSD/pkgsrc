$NetBSD: patch-cachecontrol_serialize.py,v 1.1 2023/05/30 07:39:19 wiz Exp $

disuse HTTPResponse.strict
https://github.com/ionrock/cachecontrol/commit/8f037ba1650c446759d6db581012714f6109850f

--- cachecontrol/serialize.py.orig	2022-04-19 17:16:07.000000000 +0000
+++ cachecontrol/serialize.py
@@ -51,7 +51,6 @@ class Serializer(object):
                 u"status": response.status,
                 u"version": response.version,
                 u"reason": text_type(response.reason),
-                u"strict": response.strict,
                 u"decode_content": response.decode_content,
             }
         }
@@ -138,6 +137,9 @@ class Serializer(object):
             #     TypeError: 'str' does not support the buffer interface
             body = io.BytesIO(body_raw.encode("utf8"))
 
+        # Discard any `strict` parameter serialized by older version of cachecontrol.
+        cached["response"].pop("strict", None)
+
         return HTTPResponse(body=body, preload_content=False, **cached["response"])
 
     def _loads_v0(self, request, data, body_file=None):
