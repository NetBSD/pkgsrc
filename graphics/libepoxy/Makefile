# $NetBSD: Makefile,v 1.33 2023/06/06 12:41:34 riastradh Exp $

DISTNAME=	libepoxy-1.5.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=anholt/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anholt/libepoxy
COMMENT=	Library for OpenGL function pointer management
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	epoxy.pc.in
PYTHON_FOR_BUILD_ONLY=	tool

BUILDLINK_TRANSFORM.SunOS+=	rm:-D_XOPEN_SOURCE

PLIST_VARS+=		egl

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.else
MESON_ARGS+=	-Dglx=no
.endif

.if !empty(MESALIB_SUPPORTS_EGL:M[Yy][Ee][Ss])
PLIST.egl=	yes
MESON_ARGS+=	-Degl=yes
.else
MESON_ARGS+=	-Degl=no
.endif

.include "options.mk"

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src

.include "../../devel/meson/build.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
