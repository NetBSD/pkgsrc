# $NetBSD: Makefile,v 1.29 2014/05/05 00:47:54 ryoon Exp $

DISTNAME=	cairomm-1.10.0
PKGREVISION=	10
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

PLIST_VARS+=	quartz x11

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST.quartz=	yes
.endif

.include "../../devel/libsigc++/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8
.include "../../graphics/cairo/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.cairo:Mx11)
PLIST.x11=	yes
.endif
.include "../../mk/bsd.pkg.mk"
