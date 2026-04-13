# $NetBSD: Makefile,v 1.1 2026/04/13 15:19:36 kikadf Exp $

.include "Makefile.common"

COMMENT=	Wscons(4) and kqueue(2) based port of libinput

USE_TOOLS+=	pkg-config

# wscons
ONLY_FOR_PLATFORM=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-*

MESON_ARGS+=	-Dlibwacom=false
MESON_ARGS+=	-Ddocumentation=false
MESON_ARGS+=	-Dtests=false

PKGCONFIG_OVERRIDE+=		output/meson-private/libinput.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../devel/meson/build.mk"
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/libudev-bsd/buildlink3.mk"
.include "../../devel/input-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
