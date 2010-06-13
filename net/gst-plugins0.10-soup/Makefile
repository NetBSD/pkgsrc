# $NetBSD: Makefile,v 1.2 2010/06/13 22:45:10 wiz Exp $
#

GST_PLUGINS0.10_NAME=	soup
GST_PLUGINS0.10_DIRS=	ext/soup

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

PKGREVISION=		1

.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
