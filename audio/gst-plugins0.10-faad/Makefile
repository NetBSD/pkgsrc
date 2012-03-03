# $NetBSD: Makefile,v 1.7 2012/03/03 00:14:23 wiz Exp $
#

GST_PLUGINS0.10_NAME=	faad
GST_PLUGINS0.10_DIRS=	ext/faad

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"
PKGREVISION=1

.include "../../audio/faad2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
