# $NetBSD: Makefile,v 1.7 2011/01/13 13:37:22 wiz Exp $
#

GST_PLUGINS0.10_NAME=	pango
GST_PLUGINS0.10_DIRS=	ext/pango
GST_PLUGINS0.10_FLAGS=	pango

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"
PKGREVISION=		1

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
