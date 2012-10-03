# $NetBSD: Makefile,v 1.16.2.1 2012/10/03 12:07:10 spz Exp $
#

GST_PLUGINS0.10_NAME=	pango
GST_PLUGINS0.10_DIRS=	ext/pango
GST_PLUGINS0.10_FLAGS=	pango
PKGREVISION=		3

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
