# $NetBSD: Makefile,v 1.9 2012/03/03 00:14:24 wiz Exp $
#

GST_PLUGINS0.10_NAME=	speex
GST_PLUGINS0.10_DIRS=	ext/speex
GST_PLUGINS0.10_FLAGS=	speex

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
