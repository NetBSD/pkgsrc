# $NetBSD: Makefile,v 1.6 2011/05/18 09:49:01 drochner Exp $
#

GST_PLUGINS0.10_NAME=	speex
GST_PLUGINS0.10_DIRS=	ext/speex
GST_PLUGINS0.10_FLAGS=	speex

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
