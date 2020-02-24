$NetBSD: patch-tweepy_streaming.py,v 1.1 2020/02/24 00:02:59 joerg Exp $

async is a keyword with Python 3.7+.

--- tweepy/streaming.py.orig	2020-02-22 21:32:10.478599720 +0000
+++ tweepy/streaming.py
@@ -352,9 +352,9 @@ class Stream(object):
         if resp.raw.closed:
             self.on_closed(resp)
 
-    def _start(self, async):
+    def _start(self, do_async):
         self.running = True
-        if async:
+        if do_async:
             self._thread = Thread(target=self._run)
             self._thread.start()
         else:
@@ -370,7 +370,7 @@ class Stream(object):
                    replies=None,
                    track=None,
                    locations=None,
-                   async=False,
+                   do_async=False,
                    encoding='utf8'):
         self.session.params = {'delimited': 'length'}
         if self.running:
@@ -391,34 +391,34 @@ class Stream(object):
         if track:
             self.session.params['track'] = u','.join(track).encode(encoding)
 
-        self._start(async)
+        self._start(do_async)
 
-    def firehose(self, count=None, async=False):
+    def firehose(self, count=None, do_async=False):
         self.session.params = {'delimited': 'length'}
         if self.running:
             raise TweepError('Stream object already connected!')
         self.url = '/%s/statuses/firehose.json' % STREAM_VERSION
         if count:
             self.url += '&count=%s' % count
-        self._start(async)
+        self._start(do_async)
 
-    def retweet(self, async=False):
+    def retweet(self, do_async=False):
         self.session.params = {'delimited': 'length'}
         if self.running:
             raise TweepError('Stream object already connected!')
         self.url = '/%s/statuses/retweet.json' % STREAM_VERSION
-        self._start(async)
+        self._start(do_async)
 
-    def sample(self, async=False, languages=None):
+    def sample(self, do_async=False, languages=None):
         self.session.params = {'delimited': 'length'}
         if self.running:
             raise TweepError('Stream object already connected!')
         self.url = '/%s/statuses/sample.json' % STREAM_VERSION
         if languages:
             self.session.params['language'] = ','.join(map(str, languages))
-        self._start(async)
+        self._start(do_async)
 
-    def filter(self, follow=None, track=None, async=False, locations=None,
+    def filter(self, follow=None, track=None, do_async=False, locations=None,
                stall_warnings=False, languages=None, encoding='utf8', filter_level=None):
         self.body = {}
         self.session.headers['Content-type'] = "application/x-www-form-urlencoded"
@@ -442,10 +442,10 @@ class Stream(object):
             self.body['filter_level'] = unicode(filter_level, encoding)
         self.session.params = {'delimited': 'length'}
         self.host = 'stream.twitter.com'
-        self._start(async)
+        self._start(do_async)
 
     def sitestream(self, follow, stall_warnings=False,
-                   with_='user', replies=False, async=False):
+                   with_='user', replies=False, do_async=False):
         self.body = {}
         if self.running:
             raise TweepError('Stream object already connected!')
@@ -458,7 +458,7 @@ class Stream(object):
             self.body['with'] = with_
         if replies:
             self.body['replies'] = replies
-        self._start(async)
+        self._start(do_async)
 
     def disconnect(self):
         if self.running is False:
