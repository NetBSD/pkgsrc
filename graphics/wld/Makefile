# $NetBSD: Makefile,v 1.11 2024/05/19 16:00:37 nia Exp $

DISTNAME=	wld-0.0.0.20230603
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/}
GITHUB_PROJECT=	wld
GITHUB_TAG=	ea4eccb64cfcfc508b029a530fc434d6e6695af5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/wld
COMMENT=	Primitive drawing library targeted at Wayland
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
WLD_DRIVERS+=	intel
.endif

WLD_DRIVERS+=	nouveau

MAKE_FLAGS+=	DRM_DRIVERS=${WLD_DRIVERS:Q}

PKGCONFIG_OVERRIDE+=	wld.pc.in

.include "../../devel/wayland/platform.mk"

.if empty(PLATFORM_SUPPORTS_WAYLAND:M[Yy][Ee][Ss])
PKG_SKIP_REASON+=	"Platform does not support Wayland"
.endif

.include "../../devel/wayland/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.83
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
