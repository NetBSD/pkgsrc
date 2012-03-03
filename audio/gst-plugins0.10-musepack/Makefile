# $NetBSD: Makefile,v 1.9 2012/03/03 00:14:23 wiz Exp $
#

GST_PLUGINS0.10_NAME=	musepack
GST_PLUGINS0.10_DIRS=	ext/musepack

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"
PKGREVISION=1

.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
