# $NetBSD: Makefile,v 1.15 2021/12/08 16:03:11 adam Exp $
#

GST_PLUGINS0.10_NAME=	mad
GST_PLUGINS0.10_DIRS=	ext/mad
PKGREVISION=		7

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

CONFIGURE_ARGS+=	--enable-id3tag
CONFIGURE_ARGS+=	--enable-mad

.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
