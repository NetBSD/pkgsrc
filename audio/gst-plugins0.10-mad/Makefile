# $NetBSD: Makefile,v 1.9 2012/09/12 00:24:37 asau Exp $
#

GST_PLUGINS0.10_NAME=	mad
GST_PLUGINS0.10_DIRS=	ext/mad
PKGREVISION=		1

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"
PKGREVISION=1

CONFIGURE_ARGS+=	--enable-id3tag
CONFIGURE_ARGS+=	--enable-mad

.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
