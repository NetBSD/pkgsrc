# $NetBSD: Makefile,v 1.6 2012/02/28 18:43:39 drochner Exp $
#

GST_PLUGINS0.10_NAME=	a52
GST_PLUGINS0.10_DIRS=	ext/a52dec

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
