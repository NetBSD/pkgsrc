# $NetBSD: Makefile,v 1.7 2012/02/28 18:43:43 drochner Exp $
#

GST_PLUGINS0.10_NAME=	v4l2
GST_PLUGINS0.10_DIRS=	sys/v4l2
GST_PLUGINS0.10_FLAGS=	gst_v4l2

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	NetBSD-[5-9]* Linux-*

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

CONFIGURE_ARGS+= --with-libv4l2

.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
