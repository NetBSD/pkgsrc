# $NetBSD: Makefile,v 1.4 2020/03/08 16:50:42 wiz Exp $

GST_PLUGINS1_NAME=	v4l2
GST_PLUGINS1_DIRS=	sys/v4l2
GST_PLUGINS1_FLAGS=	gst_v4l2

ONLY_FOR_PLATFORM=	NetBSD-[5-9]* Linux-* SunOS-5.11-*

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-good/Makefile.common"

.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
