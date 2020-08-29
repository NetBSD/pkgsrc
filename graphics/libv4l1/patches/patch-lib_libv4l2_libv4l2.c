$NetBSD: patch-lib_libv4l2_libv4l2.c,v 1.1 2020/08/29 22:18:42 ryoon Exp $

--- lib/libv4l2/libv4l2.c.orig	2017-12-27 13:50:55.000000000 +0000
+++ lib/libv4l2/libv4l2.c
@@ -1144,7 +1144,9 @@ int v4l2_ioctl(int fd, unsigned long int
 		break;
 	case VIDIOC_S_STD:
 	case VIDIOC_S_INPUT:
+#ifdef VIDIOC_S_DV_TIMINGS
 	case VIDIOC_S_DV_TIMINGS:
+#endif
 		is_capture_request = 1;
 		stream_needs_locking = 1;
 		break;		
@@ -1255,7 +1257,10 @@ no_capture_request:
 
 	case VIDIOC_S_STD:
 	case VIDIOC_S_INPUT:
-	case VIDIOC_S_DV_TIMINGS: {
+#ifdef VIDIOC_S_DV_TIMINGS
+	case VIDIOC_S_DV_TIMINGS:
+#endif
+	{
 		struct v4l2_format src_fmt = { 0 };
 		unsigned int orig_dest_pixelformat =
 			devices[index].dest_fmt.fmt.pix.pixelformat;
