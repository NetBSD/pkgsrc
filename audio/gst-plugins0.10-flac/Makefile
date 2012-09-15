# $NetBSD: Makefile,v 1.13 2012/09/15 10:03:37 obache Exp $
#

GST_PLUGINS0.10_NAME=	flac
GST_PLUGINS0.10_DIRS=	ext/flac
GST_PLUGINS0.10_FLAGS=	flac
PKGREVISION=		2

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

BUILDLINK_API_DEPENDS.flac+=	flac>=1.1.3nb1
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
