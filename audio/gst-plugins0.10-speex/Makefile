# $NetBSD: Makefile,v 1.3 2008/11/08 21:13:27 bjs Exp $
#

GST_PLUGINS0.10_NAME=	speex
GST_PLUGINS0.10_DIRS=	ext/speex
GST_PLUGINS0.10_FLAGS=	speex

PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
