# $NetBSD: Makefile,v 1.3 2022/06/28 11:33:59 wiz Exp $

DISTNAME=	cairomm-1.16.1
PKGNAME=	${DISTNAME:S/cairomm/cairomm1.16/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://cairographics.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://cairographics.org/cairomm/
COMMENT=	C++ API for cairo (1.16 API)
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl pkg-config
# TODO: update
PKGCONFIG_OVERRIDE+=	data/cairomm-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-ft-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-pdf-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-png-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-ps-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-quartz-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-quartz-font-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-quartz-image-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-svg-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-win32-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-win32-font-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-xlib-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/cairomm-xlib-xrender-1.0.pc.in

PLIST_VARS+=	x11 quartz

.include "../../devel/libsigc++3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/mm-common/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.12
.include "../../graphics/cairo/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.cairo:Mx11}
PLIST.x11=	yes
.endif
.if ${PKG_BUILD_OPTIONS.cairo:Mquartz}
PLIST.quartz=	yes
.endif
.include "../../mk/bsd.pkg.mk"
