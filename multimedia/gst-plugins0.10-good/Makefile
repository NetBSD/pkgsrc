# $NetBSD: Makefile,v 1.2 2006/02/05 23:10:15 joerg Exp $
#

.include "Makefile.common"

PKGREVISION=		1
COMMENT+=		good plugins

CONFIGURE_ARGS+=	--enable-gconf
CONFIGURE_ARGS+=	--enable-gconftool
CONFIGURE_ARGS+=	--enable-zlib

GCONF2_SCHEMAS=		gstreamer-0.10.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
