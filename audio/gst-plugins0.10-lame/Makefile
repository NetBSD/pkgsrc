# $NetBSD: Makefile,v 1.2 2011/04/22 13:45:21 obache Exp $
#

GST_PLUGINS0.10_NAME=	lame
GST_PLUGINS0.10_DIRS=	ext/lame

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

.include "../../audio/lame/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
