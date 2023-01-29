# $NetBSD: Makefile,v 1.54 2023/01/29 21:14:37 ryoon Exp $

DISTNAME=	cairomm-1.14.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://cairographics.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://cairographics.org/cairomm/
COMMENT=	C++ API for cairo (1.0 API)
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
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

.include "../../mk/bsd.prefs.mk"

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.mm-common+=	mm-common>=1.0.4
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
