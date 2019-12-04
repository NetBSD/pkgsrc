# $NetBSD: Makefile,v 1.15 2019/12/04 13:31:43 nros Exp $

PKGREVISION=	2

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-python

PKGCONFIG_OVERRIDE+=	libixion.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
