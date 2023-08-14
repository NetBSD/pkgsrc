# $NetBSD: Makefile,v 1.29 2023/08/14 05:24:49 wiz Exp $

PKGREVISION= 4
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-python

PKGCONFIG_OVERRIDE+=	libixion.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
