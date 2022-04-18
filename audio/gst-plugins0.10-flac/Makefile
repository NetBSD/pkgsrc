# $NetBSD: Makefile,v 1.19 2022/04/18 19:10:21 adam Exp $
#

GST_PLUGINS0.10_NAME=	flac
GST_PLUGINS0.10_DIRS=	ext/flac
GST_PLUGINS0.10_FLAGS=	flac
PKGREVISION=		8

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

BUILDLINK_API_DEPENDS.flac+=	flac>=1.1.3nb1
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
