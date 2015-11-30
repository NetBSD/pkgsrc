# $NetBSD: Makefile,v 1.15 2015/11/30 14:36:35 tnn Exp $

DISTNAME=	libepoxy-1.3.1
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=anholt/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anholt/libepoxy/
COMMENT=	Library for OpenGL function pointer management
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config autoconf autoreconf automake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	epoxy.pc.in
PYTHON_FOR_BUILD_ONLY=	yes

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		egl glx

PKG_OPTIONS_VAR=	PKG_OPTIONS.libepoxy
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
BUILD_GLX=	yes
PLIST.glx=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.  if ${OPSYS} == "Darwin"
BUILD_EGL=	no
.    if ${X11_TYPE} == "modular"
CPPFLAGS+=	-DGLX_LIB=\"${PREFIX}/lib/libGL.dylib\"
.    endif
.  else # ! Darwin
BUILD_EGL=	${MESALIB_SUPPORTS_EGL}
.    if !empty(MESALIB_SUPPORTS_EGL:Myes)
PLIST.egl=	yes
.    endif
.  endif
.else # ! x11
BUILD_GLX=	no
BUILD_EGL=	no
.  if !(${OPSYS} == "Darwin" && ${X11_TYPE} == "native")
PKG_FAIL_REASON=	"The x11 option must be enabled on this platform/configuration."
.  endif
.endif

SUBST_CLASSES+=		gl
SUBST_STAGE.gl=		pre-configure
SUBST_MESSAGE.gl=	Configuring optional EGL and GLX build.
SUBST_FILES.gl=		configure.ac
SUBST_VARS.gl=		BUILD_EGL BUILD_GLX

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../lang/python/tool.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
