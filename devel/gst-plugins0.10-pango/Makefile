# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:13 joerg Exp $
#

GST_PLUGINS0.10_NAME=	pango
GST_PLUGINS0.10_DIRS=	ext/pango
GST_PLUGINS0.10_FLAGS=	pango

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
