# $NetBSD: Makefile,v 1.3 2020/03/08 16:48:43 wiz Exp $

GST_PLUGINS1_NAME=	flac
GST_PLUGINS1_DIRS=	ext/flac
GST_PLUGINS1_FLAGS=	flac

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-good/Makefile.common"

BUILDLINK_API_DEPENDS.flac+=	flac>=1.1.3nb1
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
