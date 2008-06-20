# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:06 joerg Exp $
#

GST_PLUGINS0.8_NAME=	esound
GST_PLUGINS0.8_DIR=	ext/esd
GST_PLUGINS0.8_FLAG=	esd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		6

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
