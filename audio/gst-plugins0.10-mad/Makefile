# $NetBSD: Makefile,v 1.1.1.1 2006/04/08 11:44:28 jmmv Exp $
#

GST_PLUGINS0.10_NAME=	mad
GST_PLUGINS0.10_DIRS=	ext/mad

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

CONFIGURE_ARGS+=	--enable-id3tag
CONFIGURE_ARGS+=	--enable-mad

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
