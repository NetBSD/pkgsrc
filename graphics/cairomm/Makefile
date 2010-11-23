# $NetBSD: Makefile,v 1.15 2010/11/23 17:39:14 wiz Exp $

DISTNAME=	cairomm-1.8.6
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://cairographics.org/cairomm/
COMMENT=	C++ API for cairo
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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

.include "../../devel/libsigc++/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
