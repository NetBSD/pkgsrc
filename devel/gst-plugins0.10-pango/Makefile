# $NetBSD: Makefile,v 1.8 2011/01/26 23:30:38 drochner Exp $
#

GST_PLUGINS0.10_NAME=	pango
GST_PLUGINS0.10_DIRS=	ext/pango
GST_PLUGINS0.10_FLAGS=	pango

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
