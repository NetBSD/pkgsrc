$NetBSD: patch-src_http.c,v 1.5 2016/03/07 19:36:57 nros Exp $

* Avoid using the obsolete ftime() function.
https://trac.xiph.org/ticket/2014

* Need sys/filio.h on SunOS for FIONREAD.

--- src/http.c.orig	2015-12-31 18:29:53.000000000 +0000
+++ src/http.c
@@ -14,6 +14,9 @@
 #endif
 
 #include "internal.h"
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <ctype.h>
 #include <errno.h>
 #include <limits.h>
@@ -347,7 +350,7 @@ typedef int op_sock;
 #  define op_reset_errno() (errno=0)
 
 # endif
-# include <sys/timeb.h>
+# include <sys/time.h>
 # include <openssl/x509v3.h>
 
 /*The maximum number of simultaneous connections.
@@ -788,7 +791,7 @@ struct OpusHTTPConn{
   /*The next connection in either the LRU or free list.*/
   OpusHTTPConn *next;
   /*The last time we blocked for reading from this connection.*/
-  struct timeb  read_time;
+  struct timeval  read_time;
   /*The number of bytes we've read since the last time we blocked.*/
   opus_int64    read_bytes;
   /*The estimated throughput of this connection, in bytes/s.*/
@@ -838,7 +841,7 @@ struct OpusHTTPStream{
     struct sockaddr_in6 v6;
   }                addr;
   /*The last time we re-resolved the host.*/
-  struct timeb     resolve_time;
+  struct timeval     resolve_time;
   /*A buffer used to build HTTP requests.*/
   OpusStringBuf    request;
   /*A buffer used to build proxy CONNECT requests.*/
@@ -992,26 +995,26 @@ static int op_http_conn_estimate_availab
   return available;
 }
 
-static opus_int32 op_time_diff_ms(const struct timeb *_end,
- const struct timeb *_start){
+static opus_int32 op_time_diff_ms(const struct timeval *_end,
+ const struct timeval *_start){
   opus_int64 dtime;
-  dtime=_end->time-(opus_int64)_start->time;
-  OP_ASSERT(_end->millitm<1000);
-  OP_ASSERT(_start->millitm<1000);
+  dtime=_end->tv_sec-(opus_int64)_start->tv_sec;
+  OP_ASSERT(_end->tv_usec<1000000);
+  OP_ASSERT(_start->tv_usec<1000000);
   if(OP_UNLIKELY(dtime>(OP_INT32_MAX-1000)/1000))return OP_INT32_MAX;
   if(OP_UNLIKELY(dtime<(OP_INT32_MIN+1000)/1000))return OP_INT32_MIN;
-  return (opus_int32)dtime*1000+_end->millitm-_start->millitm;
+  return (opus_int32)dtime*1000+(_end->tv_usec-_start->tv_usec)/1000;
 }
 
 /*Update the read rate estimate for this connection.*/
 static void op_http_conn_read_rate_update(OpusHTTPConn *_conn){
-  struct timeb read_time;
+  struct timeval read_time;
   opus_int32   read_delta_ms;
   opus_int64   read_delta_bytes;
   opus_int64   read_rate;
   read_delta_bytes=_conn->read_bytes;
   if(read_delta_bytes<=0)return;
-  ftime(&read_time);
+  gettimeofday(&read_time, NULL);
   read_delta_ms=op_time_diff_ms(&read_time,&_conn->read_time);
   read_rate=_conn->read_rate;
   read_delta_ms=OP_MAX(read_delta_ms,1);
@@ -1902,7 +1905,7 @@ static int op_sock_connect_next(op_sock 
 # define OP_NPROTOS (2)
 
 static int op_http_connect_impl(OpusHTTPStream *_stream,OpusHTTPConn *_conn,
- const struct addrinfo *_addrs,struct timeb *_start_time){
+ const struct addrinfo *_addrs,struct timeval *_start_time){
   const struct addrinfo *addr;
   const struct addrinfo *addrs[OP_NPROTOS];
   struct pollfd          fds[OP_NPROTOS];
@@ -1932,7 +1935,7 @@ static int op_http_connect_impl(OpusHTTP
   _stream->free_head=_conn->next;
   _conn->next=_stream->lru_head;
   _stream->lru_head=_conn;
-  ftime(_start_time);
+  gettimeofday(_start_time, NULL);
   *&_conn->read_time=*_start_time;
   _conn->read_bytes=0;
   _conn->read_rate=0;
@@ -2034,14 +2037,14 @@ static int op_http_connect_impl(OpusHTTP
 }
 
 static int op_http_connect(OpusHTTPStream *_stream,OpusHTTPConn *_conn,
- const struct addrinfo *_addrs,struct timeb *_start_time){
-  struct timeb     resolve_time;
+ const struct addrinfo *_addrs,struct timeval *_start_time){
+  struct timeval     resolve_time;
   struct addrinfo *new_addrs;
   int              ret;
   /*Re-resolve the host if we need to (RFC 6555 says we MUST do so
      occasionally).*/
   new_addrs=NULL;
-  ftime(&resolve_time);
+  gettimeofday(&resolve_time, NULL);
   if(_addrs!=&_stream->addr_info||op_time_diff_ms(&resolve_time,
    &_stream->resolve_time)>=OP_RESOLVE_CACHE_TIMEOUT_MS){
     new_addrs=op_resolve(_stream->connect_host,_stream->connect_port);
@@ -2191,8 +2194,8 @@ static int op_http_stream_open(OpusHTTPS
   addrs=NULL;
   for(nredirs=0;nredirs<OP_REDIRECT_LIMIT;nredirs++){
     OpusParsedURL  next_url;
-    struct timeb   start_time;
-    struct timeb   end_time;
+    struct timeval   start_time;
+    struct timeval   end_time;
     char          *next;
     char          *status_code;
     int            minor_version_pos;
@@ -2321,7 +2324,7 @@ static int op_http_stream_open(OpusHTTPS
     if(OP_UNLIKELY(ret<0))return ret;
     ret=op_http_conn_read_response(_stream->conns+0,&_stream->response);
     if(OP_UNLIKELY(ret<0))return ret;
-    ftime(&end_time);
+    gettimeofday(&end_time, NULL);
     next=op_http_parse_status_line(&v1_1_compat,&status_code,
      _stream->response.buf);
     if(OP_UNLIKELY(next==NULL))return OP_FALSE;
@@ -2733,8 +2736,8 @@ static int op_http_conn_handle_response(
                 converted into a request for the rest.*/
 static int op_http_conn_open_pos(OpusHTTPStream *_stream,
  OpusHTTPConn *_conn,opus_int64 _pos,opus_int32 _chunk_size){
-  struct timeb  start_time;
-  struct timeb  end_time;
+  struct timeval  start_time;
+  struct timeval  end_time;
   opus_int32    connect_rate;
   opus_int32    connect_time;
   int           ret;
@@ -2744,7 +2747,7 @@ static int op_http_conn_open_pos(OpusHTT
   if(OP_UNLIKELY(ret<0))return ret;
   ret=op_http_conn_handle_response(_stream,_conn);
   if(OP_UNLIKELY(ret!=0))return OP_FALSE;
-  ftime(&end_time);
+  gettimeofday(&end_time, NULL);
   _stream->cur_conni=_conn-_stream->conns;
   OP_ASSERT(_stream->cur_conni>=0&&_stream->cur_conni<OP_NCONNS_MAX);
   /*The connection has been successfully opened.
@@ -2996,7 +2999,7 @@ static int op_http_conn_read_ahead(OpusH
 }
 
 static int op_http_stream_seek(void *_stream,opus_int64 _offset,int _whence){
-  struct timeb     seek_time;
+  struct timeval     seek_time;
   OpusHTTPStream  *stream;
   OpusHTTPConn    *conn;
   OpusHTTPConn   **pnext;
@@ -3037,7 +3040,7 @@ static int op_http_stream_seek(void *_st
     op_http_conn_read_rate_update(stream->conns+ci);
     *&seek_time=*&stream->conns[ci].read_time;
   }
-  else ftime(&seek_time);
+  else gettimeofday(&seek_time, NULL);
   /*If we seeked past the end of the stream, just disable the active
      connection.*/
   if(pos>=content_length){
