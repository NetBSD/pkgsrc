# $NetBSD: Makefile,v 1.5 2012/02/06 12:39:23 wiz Exp $
#

GST_PLUGINS0.10_NAME=	a52
GST_PLUGINS0.10_DIRS=	ext/a52dec

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

PKGREVISION=		1

.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
