# $NetBSD: Makefile,v 1.26 2024/02/21 11:12:01 nia Exp $

DISTNAME=	orc-0.4.37
CATEGORIES=	devel
MASTER_SITES=	https://gstreamer.freedesktop.org/src/orc/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/modules/orc.html
COMMENT=	Compiler for vector operations
LICENSE=	modified-bsd

PKGCONFIG_OVERRIDE+=		output/orc-0.4.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/orc-test-0.4.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/orc:${WRKSRC}/output/orc-test
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/orc:${WRKSRC}/output/orc-test

MESON_ARGS+=	-Dgtk_doc=disabled

USE_CC_FEATURES+=	c99
FORCE_C_STD=		c99

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
