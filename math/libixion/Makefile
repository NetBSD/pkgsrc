# $NetBSD: Makefile,v 1.37 2025/08/21 16:57:07 ryoon Exp $

PKGREVISION= 4
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_DIR.boost-libs}

PKGCONFIG_OVERRIDE+=	libixion.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
