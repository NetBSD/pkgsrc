# $NetBSD: Makefile,v 1.5 2020/04/29 21:22:58 maya Exp $

GST_PLUGINS1_NAME=	v4l2
GST_PLUGINS1_DIRS=	sys/v4l2
GST_PLUGINS1_FLAGS=	gst_v4l2

ONLY_FOR_PLATFORM=	NetBSD-* Linux-* SunOS-5.11-*

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-good/Makefile.common"

.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
