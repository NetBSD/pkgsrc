# $NetBSD: Makefile,v 1.8 2012/06/14 07:44:17 sbd Exp $
#

GST_PLUGINS0.10_NAME=	a52
GST_PLUGINS0.10_DIRS=	ext/a52dec

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"
PKGREVISION=		2

.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
