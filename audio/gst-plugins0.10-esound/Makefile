# $NetBSD: Makefile,v 1.10 2012/06/14 07:44:18 sbd Exp $
#

GST_PLUGINS0.10_NAME=	esound
GST_PLUGINS0.10_DIRS=	ext/esd
GST_PLUGINS0.10_FLAGS=	esd
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
