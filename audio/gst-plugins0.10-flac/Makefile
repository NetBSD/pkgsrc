# $NetBSD: Makefile,v 1.22 2023/04/19 08:09:05 adam Exp $
#

GST_PLUGINS0.10_NAME=	flac
GST_PLUGINS0.10_DIRS=	ext/flac
GST_PLUGINS0.10_FLAGS=	flac
PKGREVISION=		11

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

BUILDLINK_API_DEPENDS.flac+=	flac>=1.1.3nb1
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
