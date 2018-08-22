# $NetBSD: Makefile,v 1.41 2018/08/22 09:45:11 wiz Exp $

DISTNAME=	cairomm-1.12.2
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://cairographics.org/cairomm/
COMMENT=	C++ API for cairo
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes
# long file name, does not extract correctly with NetBSD tar(1):
# classhash__load__check__resize__trigger__size__base__inherit__graph.png
EXTRACT_USING=		bsdtar

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

CONFIGURE_ARGS+=	--disable-docs

PLIST_VARS+=	x11 quartz

.include "../../mk/bsd.prefs.mk"

BUILDLINK_ABI_DEPENDS.libsigcpp+=	libsigc++>=2.5.1
.include "../../devel/libsigc++/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8
.include "../../graphics/cairo/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.cairo:Mx11)
PLIST.x11=	yes
.endif
.if !empty(PKG_BUILD_OPTIONS.cairo:Mquartz)
PLIST.quartz=	yes
.endif
.include "../../mk/bsd.pkg.mk"
