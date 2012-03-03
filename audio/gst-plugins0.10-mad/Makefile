# $NetBSD: Makefile,v 1.7 2012/03/03 00:14:23 wiz Exp $
#

GST_PLUGINS0.10_NAME=	mad
GST_PLUGINS0.10_DIRS=	ext/mad

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"
PKGREVISION=1

CONFIGURE_ARGS+=	--enable-id3tag
CONFIGURE_ARGS+=	--enable-mad

.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
