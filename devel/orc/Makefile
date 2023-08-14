# $NetBSD: Makefile,v 1.23 2023/08/14 05:24:13 wiz Exp $

DISTNAME=	orc-0.4.34
PKGREVISION=	1
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

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/${PKGBASE}
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/${PKGBASE}

MESON_ARGS+=	-Dgtk_doc=disabled

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
