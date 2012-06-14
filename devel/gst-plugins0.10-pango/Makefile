# $NetBSD: Makefile,v 1.15 2012/06/14 07:45:16 sbd Exp $
#

GST_PLUGINS0.10_NAME=	pango
GST_PLUGINS0.10_DIRS=	ext/pango
GST_PLUGINS0.10_FLAGS=	pango
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"
PKGREVISION=1

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
