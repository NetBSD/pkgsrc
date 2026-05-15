# $NetBSD: Makefile,v 1.42 2026/05/15 09:58:56 adam Exp $

PKGREVISION= 3
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_DIR.boost-libs}
# Fix for boost-1.89.0 where boost_system is header-only.
CONFIGURE_ENV+=		boost_cv_lib_system=yes

PKGCONFIG_OVERRIDE+=	libixion.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
