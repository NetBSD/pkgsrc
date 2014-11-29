# $NetBSD: Makefile,v 1.3 2014/11/29 13:48:11 jmcneill Exp $

GST_PLUGINS1_NAME=	v4l2
GST_PLUGINS1_DIRS=	sys/v4l2
GST_PLUGINS1_FLAGS=	gst_v4l2

ONLY_FOR_PLATFORM=	NetBSD-[5-9]* Linux-* SunOS-5.11-*

.include "../../multimedia/gst-plugins1-good/Makefile.common"

.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
