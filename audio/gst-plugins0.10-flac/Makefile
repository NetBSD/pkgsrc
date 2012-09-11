# $NetBSD: Makefile,v 1.12 2012/09/12 00:24:37 asau Exp $
#

GST_PLUGINS0.10_NAME=	flac
GST_PLUGINS0.10_DIRS=	ext/flac
GST_PLUGINS0.10_FLAGS=	flac
PKGREVISION=		1

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

BUILDLINK_API_DEPENDS.flac+=	flac>=1.1.3nb1
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
