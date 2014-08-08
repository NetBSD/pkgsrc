# $NetBSD: Makefile,v 1.2 2014/08/08 21:31:07 wiz Exp $

GST_PLUGINS1_NAME=	mad
GST_PLUGINS1_DIRS=	ext/mad

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"

CONFIGURE_ARGS+=	--enable-mad

.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
