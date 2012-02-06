# $NetBSD: Makefile,v 1.4 2012/02/06 12:39:23 wiz Exp $
#

GST_PLUGINS0.10_NAME=	faac
GST_PLUGINS0.10_DIRS=	ext/faac

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

PKGREVISION=		1

.include "../../audio/faac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
