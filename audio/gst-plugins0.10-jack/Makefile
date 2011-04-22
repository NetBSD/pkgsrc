# $NetBSD: Makefile,v 1.6 2011/04/22 13:45:21 obache Exp $
#

GST_PLUGINS0.10_NAME=	jack
GST_PLUGINS0.10_DIRS=	ext/jack

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
