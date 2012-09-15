# $NetBSD: Makefile,v 1.16 2012/09/15 10:04:11 obache Exp $
#

GST_PLUGINS0.10_NAME=	pango
GST_PLUGINS0.10_DIRS=	ext/pango
GST_PLUGINS0.10_FLAGS=	pango
PKGREVISION=		2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
