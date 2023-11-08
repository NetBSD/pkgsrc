$NetBSD: patch-src_RtMidi.cpp,v 1.2 2023/11/08 16:49:02 bacon Exp $

Use process scheduling from NetBSD instead of pthread.

--- src/RtMidi.cpp.orig	2023-09-12 07:28:28.679052163 +0000
+++ src/RtMidi.cpp
@@ -3608,8 +3608,11 @@ void MidiOutJack :: sendMessage( const u
       return;
 
   while ( jack_ringbuffer_write_space(data->buff) < sizeof(nBytes) + size )
+#if defined(__NetBSD__) || defined(__APPLE__)
+      sched_yield();
+#else
       pthread_yield();
-
+#endif
   // Write full message to buffer
   jack_ringbuffer_write( data->buff, ( char * ) &nBytes, sizeof( nBytes ) );
   jack_ringbuffer_write( data->buff, ( const char * ) message, nBytes );
