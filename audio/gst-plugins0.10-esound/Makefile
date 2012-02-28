# $NetBSD: Makefile,v 1.8 2012/02/28 18:43:40 drochner Exp $
#

GST_PLUGINS0.10_NAME=	esound
GST_PLUGINS0.10_DIRS=	ext/esd
GST_PLUGINS0.10_FLAGS=	esd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
