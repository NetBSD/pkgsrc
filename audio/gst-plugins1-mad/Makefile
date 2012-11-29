# $NetBSD: Makefile,v 1.1 2012/11/29 09:17:39 ryoon Exp $
#

GST_PLUGINS1_NAME=	mad
GST_PLUGINS1_DIRS=	ext/mad

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"

CONFIGURE_ARGS+=	--enable-mad

.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
