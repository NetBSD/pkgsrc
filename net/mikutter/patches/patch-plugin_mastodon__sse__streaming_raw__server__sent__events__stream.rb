$NetBSD: patch-plugin_mastodon__sse__streaming_raw__server__sent__events__stream.rb,v 1.1 2023/07/23 17:20:12 tsutsui Exp $

- pull upstream fix https://dev.mikutter.hachune.net/issues/1591

--- plugin/mastodon_sse_streaming/raw_server_sent_events_stream.rb.orig	2022-01-29 23:56:32.000000000 +0000
+++ plugin/mastodon_sse_streaming/raw_server_sent_events_stream.rb
@@ -29,17 +29,16 @@ module Plugin::MastodonSseStreaming
         client = HTTPClient.new
         client.ssl_config.set_default_paths
         notice "connect #{@connection_type.perma_link} (#{@connection_type})"
-        response = client.request(:get, @connection_type.perma_link.to_s, {}, {}, headers) do |fragment|
-          yielder << fragment
-        end
-        if response
-          raise ResponseError.new(
-            response.reason,
-            code: response.status_code,
-            response: response
-          )
-        else
-          raise ConnectionRefusedError
+        client.request(:get, @connection_type.perma_link.to_s, {}, {}, headers) do |response, part|
+          if response.ok?
+            yielder << part
+          else
+            raise ResponseError.new(
+              response.reason,
+              code: response.status_code,
+              response: response
+            )
+          end
         end
       rescue SocketError,
              HTTPClient::BadResponseError,
