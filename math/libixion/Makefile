# $NetBSD: Makefile,v 1.40 2025/09/27 07:09:27 adam Exp $

PKGREVISION= 1
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
