# $NetBSD: Makefile,v 1.13 2020/11/05 09:07:26 ryoon Exp $
#

GST_PLUGINS0.10_NAME=	mad
GST_PLUGINS0.10_DIRS=	ext/mad
PKGREVISION=		5

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

CONFIGURE_ARGS+=	--enable-id3tag
CONFIGURE_ARGS+=	--enable-mad

.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
