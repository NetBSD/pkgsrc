# $NetBSD: Makefile,v 1.11 2012/06/14 07:44:19 sbd Exp $
#

GST_PLUGINS0.10_NAME=	jack
GST_PLUGINS0.10_DIRS=	ext/jack
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
