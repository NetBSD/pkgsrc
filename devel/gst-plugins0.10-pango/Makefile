# $NetBSD: Makefile,v 1.17 2012/10/02 17:10:47 tron Exp $
#

GST_PLUGINS0.10_NAME=	pango
GST_PLUGINS0.10_DIRS=	ext/pango
GST_PLUGINS0.10_FLAGS=	pango
PKGREVISION=		3

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
