# $NetBSD: Makefile,v 1.7 2012/03/03 00:14:22 wiz Exp $
#

GST_PLUGINS0.10_NAME=	a52
GST_PLUGINS0.10_DIRS=	ext/a52dec

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"
PKGREVISION=		1

.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
