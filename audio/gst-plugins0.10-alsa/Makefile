# $NetBSD: Makefile,v 1.4 2012/06/14 07:45:17 sbd Exp $
#

GST_PLUGINS0.10_NAME=	alsa
GST_PLUGINS0.10_DIRS=	ext/alsa
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
