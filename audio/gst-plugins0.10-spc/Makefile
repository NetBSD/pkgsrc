# $NetBSD: Makefile,v 1.5 2012/02/06 12:39:24 wiz Exp $
#

GST_PLUGINS0.10_NAME=	spc
GST_PLUGINS0.10_DIRS=	ext/spc

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

PKGREVISION=		1

.include "../../audio/libopenspc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
