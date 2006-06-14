# $NetBSD: Makefile,v 1.5 2006/06/14 11:23:17 drochner Exp $
#

.include "Makefile.common"

COMMENT+=		good plugins

CONFIGURE_ARGS+=	--enable-gconf
CONFIGURE_ARGS+=	--enable-gconftool
CONFIGURE_ARGS+=	--enable-zlib

GCONF2_SCHEMAS=		gstreamer-0.10.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
