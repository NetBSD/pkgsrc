# $NetBSD: Makefile,v 1.27 2019/09/01 20:38:34 dholland Exp $

DISTNAME=	libepoxy-1.5.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=anholt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anholt/libepoxy/
COMMENT=	Library for OpenGL function pointer management
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config autoconf autoreconf automake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	epoxy.pc.in
PYTHON_FOR_BUILD_ONLY=	tool

PLIST_VARS+=		egl

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../graphics/MesaLib/buildlink3.mk"
.if !empty(MESALIB_SUPPORTS_EGL:M[Yy][Ee][Ss])
PLIST.egl=		yes
.else
CONFIGURE_ARGS+=	--disable-egl
.endif

.include "options.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
