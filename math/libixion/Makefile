# $NetBSD: Makefile,v 1.39 2025/09/21 18:15:09 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_DIR.boost-libs}

PKGCONFIG_OVERRIDE+=	libixion.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
