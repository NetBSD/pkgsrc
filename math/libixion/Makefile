# $NetBSD: Makefile,v 1.34 2024/10/04 03:49:30 ryoon Exp $

PKGREVISION= 2
.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-python

PKGCONFIG_OVERRIDE+=	libixion.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
