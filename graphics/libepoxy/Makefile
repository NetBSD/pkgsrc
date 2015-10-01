# $NetBSD: Makefile,v 1.12 2015/10/01 13:50:05 tnn Exp $

DISTNAME=	libepoxy-1.3.1
PKGREVISION=	2
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
CONFIGURE_ENV+=		PKGSRC_BUILD_EGL=${MESALIB_SUPPORTS_EGL}

# This could be garbage collected, but it seems likely that there will
# be more glx issues, so it seems easier to leave it.
PLIST_VARS+=		glx
.if ${OPSYS} != "Darwin"
PLIST.glx=		yes
.else
# On Darwin, we patch upstream to enable this.
PLIST.glx=		yes
.endif

.if ${OPSYS} == "Darwin" && ${X11_TYPE} == "modular"
CPPFLAGS+=	-DGLX_LIB=\"${PREFIX}/lib/libGL.1.dylib\"
.endif

.include "../../lang/python/tool.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.if !empty(MESALIB_SUPPORTS_EGL:Myes) && ${OPSYS} != "Darwin"
PLIST.egl=		yes
.endif
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
