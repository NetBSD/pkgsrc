# $NetBSD: Makefile,v 1.5 2012/06/14 07:45:16 sbd Exp $
#

GST_PLUGINS0.10_NAME=	ogg
GST_PLUGINS0.10_DIRS=	ext/ogg
GST_PLUGINS0.10_FLAGS=	ogg
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
