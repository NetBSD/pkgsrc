# $NetBSD: Makefile,v 1.8 2012/02/06 12:39:24 wiz Exp $
#

GST_PLUGINS0.10_NAME=	jack
GST_PLUGINS0.10_DIRS=	ext/jack

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

PKGREVISION=		1

.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
