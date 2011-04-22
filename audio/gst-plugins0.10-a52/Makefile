# $NetBSD: Makefile,v 1.3 2011/04/22 13:45:21 obache Exp $
#

GST_PLUGINS0.10_NAME=	a52
GST_PLUGINS0.10_DIRS=	ext/a52dec

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
