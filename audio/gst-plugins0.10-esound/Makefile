# $NetBSD: Makefile,v 1.7 2012/02/06 12:39:23 wiz Exp $
#

GST_PLUGINS0.10_NAME=	esound
GST_PLUGINS0.10_DIRS=	ext/esd
GST_PLUGINS0.10_FLAGS=	esd

PKGREVISION=	2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
