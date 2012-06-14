# $NetBSD: Makefile,v 1.10 2012/06/14 07:44:19 sbd Exp $
#

GST_PLUGINS0.10_NAME=	speex
GST_PLUGINS0.10_DIRS=	ext/speex
GST_PLUGINS0.10_FLAGS=	speex
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
