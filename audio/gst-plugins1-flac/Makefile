# $NetBSD: Makefile,v 1.1 2012/11/29 08:39:28 ryoon Exp $
#

GST_PLUGINS1_NAME=	flac
GST_PLUGINS1_DIRS=	ext/flac
GST_PLUGINS1_FLAGS=	flac

.include "../../multimedia/gst-plugins1-good/Makefile.common"

BUILDLINK_API_DEPENDS.flac+=	flac>=1.1.3nb1
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
