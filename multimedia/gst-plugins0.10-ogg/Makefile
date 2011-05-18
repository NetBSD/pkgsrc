# $NetBSD: Makefile,v 1.4 2011/05/18 09:49:02 drochner Exp $
#

GST_PLUGINS0.10_NAME=	ogg
GST_PLUGINS0.10_DIRS=	ext/ogg
GST_PLUGINS0.10_FLAGS=	ogg

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
