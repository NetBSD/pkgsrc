# $NetBSD: Makefile,v 1.4 2011/04/22 13:45:20 obache Exp $
#

GST_PLUGINS0.10_NAME=	esound
GST_PLUGINS0.10_DIRS=	ext/esd
GST_PLUGINS0.10_FLAGS=	esd

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
