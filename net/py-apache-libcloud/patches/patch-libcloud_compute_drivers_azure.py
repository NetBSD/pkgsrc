$NetBSD: patch-libcloud_compute_drivers_azure.py,v 1.1 2018/12/27 15:05:27 joerg Exp $

--- libcloud/compute/drivers/azure.py.orig	2018-12-25 21:46:13.858442899 +0000
+++ libcloud/compute/drivers/azure.py
@@ -1435,7 +1435,7 @@ class AzureNodeDriver(NodeDriver):
 
         return response
 
-    def _perform_post(self, path, body, response_type=None, async=False):
+    def _perform_post(self, path, body, response_type=None, is_async=False):
         request = AzureHTTPRequest()
         request.method = 'POST'
         request.host = AZURE_SERVICE_MANAGEMENT_HOST
@@ -1447,7 +1447,7 @@ class AzureNodeDriver(NodeDriver):
 
         return response
 
-    def _perform_put(self, path, body, response_type=None, async=False):
+    def _perform_put(self, path, body, response_type=None, is_async=False):
         request = AzureHTTPRequest()
         request.method = 'PUT'
         request.host = AZURE_SERVICE_MANAGEMENT_HOST
@@ -1459,7 +1459,7 @@ class AzureNodeDriver(NodeDriver):
 
         return response
 
-    def _perform_delete(self, path, async=False):
+    def _perform_delete(self, path, is_async=False):
         request = AzureHTTPRequest()
         request.method = 'DELETE'
         request.host = AZURE_SERVICE_MANAGEMENT_HOST
@@ -1470,7 +1470,7 @@ class AzureNodeDriver(NodeDriver):
 
         self.raise_for_response(response, 202)
 
-        if async:
+        if is_async:
             return self._parse_response_for_async_op(response)
 
     def _perform_request(self, request):
