# $NetBSD: Makefile,v 1.3 2008/07/25 14:03:30 obache Exp $
#

GST_PLUGINS0.10_NAME=	musepack
GST_PLUGINS0.10_DIRS=	ext/musepack

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

PKGREVISION=	1

.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
