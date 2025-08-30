# $NetBSD: Makefile,v 1.38 2025/08/30 05:05:15 ryoon Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_DIR.boost-libs}

PKGCONFIG_OVERRIDE+=	libixion.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
