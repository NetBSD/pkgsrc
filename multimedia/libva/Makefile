# $NetBSD: Makefile,v 1.1.1.1 2011/01/19 04:15:41 jmcneill Exp $
#

# libva-1.0.7+ needs libdrm-2.4.23
DISTNAME=	libva-1.0.6
CATEGORIES=	multimedia
MASTER_SITES=	http://cgit.freedesktop.org/libva/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/vaapi
COMMENT=	Video Acceleration API
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf autoconf automake gmake pkg-config

.include "../../mk/bsd.prefs.mk"

DRIVER_SEARCH_PATH=	${PREFIX}/lib/xorg/modules/dri

CONFIGURE_ARGS+=	--enable-i965-driver
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-drivers-path=${DRIVER_SEARCH_PATH}

PKGCONFIG_OVERRIDE+=	libva-glx.pc.in
PKGCONFIG_OVERRIDE+=	libva-tpi.pc.in
PKGCONFIG_OVERRIDE+=	libva-x11.pc.in
PKGCONFIG_OVERRIDE+=	libva.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
