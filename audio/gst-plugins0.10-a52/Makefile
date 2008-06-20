# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:06 joerg Exp $
#

GST_PLUGINS0.10_NAME=	a52
GST_PLUGINS0.10_DIRS=	ext/a52dec

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
