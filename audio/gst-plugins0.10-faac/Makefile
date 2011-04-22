# $NetBSD: Makefile,v 1.2 2011/04/22 13:45:20 obache Exp $
#

GST_PLUGINS0.10_NAME=	faac
GST_PLUGINS0.10_DIRS=	ext/faac

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

.include "../../audio/faac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
