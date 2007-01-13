# $NetBSD: Makefile,v 1.3 2007/01/13 09:19:07 wiz Exp $
#

GST_PLUGINS0.10_NAME=	flac
GST_PLUGINS0.10_DIRS=	ext/flac
GST_PLUGINS0.10_FLAGS=	flac

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=		1

BUILDLINK_API_DEPENDS.flac+=	flac>=1.1.3nb1
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
