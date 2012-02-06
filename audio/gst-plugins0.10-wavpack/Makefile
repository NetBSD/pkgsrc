# $NetBSD: Makefile,v 1.6 2012/02/06 12:39:25 wiz Exp $
#

GST_PLUGINS0.10_NAME=	wavpack
GST_PLUGINS0.10_DIRS=	ext/wavpack

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

PKGREVISION=		1

.include "../../audio/wavpack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
