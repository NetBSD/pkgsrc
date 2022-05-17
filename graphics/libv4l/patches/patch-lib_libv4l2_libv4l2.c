$NetBSD: patch-lib_libv4l2_libv4l2.c,v 1.2 2022/05/17 11:55:23 jperkin Exp $

Support SunOS.

--- lib/libv4l2/libv4l2.c.orig	2020-05-02 12:16:20.000000000 +0000
+++ lib/libv4l2/libv4l2.c
@@ -880,7 +880,11 @@ int v4l2_dup(int fd)
 	int index = v4l2_get_index(fd);
 
 	if (index == -1)
+#ifdef __sun
+		return syscall(SYS_fcntl, fd, F_DUPFD, 0);
+#else
 		return syscall(SYS_dup, fd);
+#endif
 
 	devices[index].open_count++;
 
@@ -1144,7 +1148,9 @@ int v4l2_ioctl(int fd, unsigned long int
 		break;
 	case VIDIOC_S_STD:
 	case VIDIOC_S_INPUT:
+#ifdef VIDIOC_S_DV_TIMINGS
 	case VIDIOC_S_DV_TIMINGS:
+#endif
 		is_capture_request = 1;
 		stream_needs_locking = 1;
 		break;		
@@ -1255,7 +1261,10 @@ no_capture_request:
 
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
