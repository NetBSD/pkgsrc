# $NetBSD: Makefile,v 1.18 2017/09/14 11:33:33 adam Exp $

DISTNAME=	libva-1.8.3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=01org/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/01org/libva
COMMENT=	Video Acceleration API
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf autoconf automake gmake pkg-config

.include "../../mk/bsd.prefs.mk"

#
# vaapi drivers (e.g. intel-vaapi-driver) can be installed under
# ${PREFIX}/lib/dri and linked against native X.org. Instruct libva's
# DRIVER_SEARCH_PATH to look at them too for native X.org.
#
.if ${X11_TYPE} == "native"
DRIVER_SEARCH_PATH=	${X11BASE}/lib/dri:${PREFIX}/lib/dri
.else
DRIVER_SEARCH_PATH=	${X11BASE}/lib/dri
.endif

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-drivers-path=${DRIVER_SEARCH_PATH:Q}

LIBS+=			${BUILDLINK_LDADD.dl}

PKGCONFIG_OVERRIDE+=	libva-drm.pc.in
PKGCONFIG_OVERRIDE+=	libva-egl.pc.in
PKGCONFIG_OVERRIDE+=	libva-glx.pc.in
PKGCONFIG_OVERRIDE+=	libva-tpi.pc.in
PKGCONFIG_OVERRIDE+=	libva-x11.pc.in
PKGCONFIG_OVERRIDE+=	libva.pc.in


pre-configure:
	cd ${WRKSRC} && autoreconf -i

# To avoid a PLIST mismatch with base Xorg
CONFIGURE_ARGS+=	--disable-glx
CONFIGURE_ARGS+=	--disable-egl

.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
