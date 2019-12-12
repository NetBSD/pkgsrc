# $NetBSD: Makefile,v 1.2 2019/12/12 14:48:43 nia Exp $

DISTNAME=	wld-0.0.0.20191211
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=niacat/}
GITHUB_PROJECT=	wld
GITHUB_TAG=	cf05d2bdcb418a686258bf02538136077dc1ace7

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/niacat/wld
COMMENT=	Primitive drawing library targeted at Wayland
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

PKGCONFIG_OVERRIDE+=	wld.pc.in

.include "../../devel/wayland/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.83
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
