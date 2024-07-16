# $NetBSD: Makefile,v 1.33 2024/07/16 10:02:04 prlw1 Exp $

PKGREVISION= 1
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-python

PKGCONFIG_OVERRIDE+=	libixion.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
