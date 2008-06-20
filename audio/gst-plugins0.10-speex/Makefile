# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:06 joerg Exp $
#

GST_PLUGINS0.10_NAME=	speex
GST_PLUGINS0.10_DIRS=	ext/speex
GST_PLUGINS0.10_FLAGS=	speex

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
