# $NetBSD: Makefile,v 1.14 2020/03/08 16:50:41 wiz Exp $
#

GST_PLUGINS0.10_NAME=	v4l2
GST_PLUGINS0.10_DIRS=	sys/v4l2
GST_PLUGINS0.10_FLAGS=	gst_v4l2
PKGREVISION=		3

ONLY_FOR_PLATFORM=	NetBSD-[5-9]* Linux-* SunOS-5.11-*

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

CONFIGURE_ARGS+=	--with-libv4l2

.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
