# $NetBSD: Makefile,v 1.5 2011/05/18 09:48:59 drochner Exp $
#

GST_PLUGINS0.10_NAME=	esound
GST_PLUGINS0.10_DIRS=	ext/esd
GST_PLUGINS0.10_FLAGS=	esd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
