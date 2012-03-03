# $NetBSD: Makefile,v 1.10 2012/03/03 00:14:23 wiz Exp $
#

GST_PLUGINS0.10_NAME=	jack
GST_PLUGINS0.10_DIRS=	ext/jack

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
