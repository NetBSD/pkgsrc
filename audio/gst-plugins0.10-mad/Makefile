# $NetBSD: Makefile,v 1.4 2011/05/18 09:49:00 drochner Exp $
#

GST_PLUGINS0.10_NAME=	mad
GST_PLUGINS0.10_DIRS=	ext/mad

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

CONFIGURE_ARGS+=	--enable-id3tag
CONFIGURE_ARGS+=	--enable-mad

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
