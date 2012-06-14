# $NetBSD: Makefile,v 1.7 2012/06/14 07:45:16 sbd Exp $
#

GST_PLUGINS0.10_NAME=	libvisual
GST_PLUGINS0.10_DIRS=	ext/libvisual
GST_PLUGINS0.10_FLAGS=	libvisual
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../audio/libvisual/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
