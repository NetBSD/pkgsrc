# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:27 joerg Exp $
#

GST_PLUGINS0.10_NAME=	theora
GST_PLUGINS0.10_DIRS=	ext/theora
GST_PLUGINS0.10_FLAGS=	theora

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
