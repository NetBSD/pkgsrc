# $NetBSD: Makefile,v 1.4 2011/05/18 09:48:59 drochner Exp $
#

GST_PLUGINS0.10_NAME=	a52
GST_PLUGINS0.10_DIRS=	ext/a52dec

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
