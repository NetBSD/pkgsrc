# $NetBSD: Makefile,v 1.4 2012/02/06 12:39:24 wiz Exp $
#

GST_PLUGINS0.10_NAME=	lame
GST_PLUGINS0.10_DIRS=	ext/lame

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

PKGREVISION=		1

.include "../../audio/lame/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
