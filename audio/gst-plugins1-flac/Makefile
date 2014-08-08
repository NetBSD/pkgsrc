# $NetBSD: Makefile,v 1.2 2014/08/08 21:31:07 wiz Exp $

GST_PLUGINS1_NAME=	flac
GST_PLUGINS1_DIRS=	ext/flac
GST_PLUGINS1_FLAGS=	flac

.include "../../multimedia/gst-plugins1-good/Makefile.common"

BUILDLINK_API_DEPENDS.flac+=	flac>=1.1.3nb1
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
