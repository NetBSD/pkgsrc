# $NetBSD: Makefile,v 1.4 2011/05/18 09:49:02 drochner Exp $
#

GST_PLUGINS0.10_NAME=	theora
GST_PLUGINS0.10_DIRS=	ext/theora
GST_PLUGINS0.10_FLAGS=	theora

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
