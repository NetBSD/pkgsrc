# $NetBSD: Makefile,v 1.7 2015/09/13 11:38:32 tron Exp $

DISTNAME=	libepoxy-1.3.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=anholt/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anholt/libepoxy/
COMMENT=	Library for OpenGL function pointer management
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

USE_TOOLS+=	pkg-config autoconf autoreconf automake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
PYTHON_FOR_BUILD_ONLY=	yes

PKGCONFIG_OVERRIDE+=	epoxy.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		egl
.if ${X11_TYPE} == "modular" || exists(${X11BASE}/include/EGL/egl.h)
PLIST.egl=		yes
CONFIGURE_ENV+=		PKGSRC_BUILD_EGL=yes
.else
CONFIGURE_ENV+=		PKGSRC_BUILD_EGL=no
.endif

PLIST_VARS+=		glx
.if ${OPSYS} != "Darwin"
PLIST.glx=		yes
.endif

.include "../../lang/python/tool.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
