# $NetBSD: Makefile,v 1.11 2026/03/26 13:58:33 wiz Exp $

DISTNAME=	libfyaml-0.9.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pantoniou/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pantoniou/libfyaml
COMMENT=	Feature-complete YAML parser and emitter
LICENSE=	mit

PKGCONFIG_OVERRIDE+=	cmake/libfyaml.pc.in

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF

.if ${MACHINE_ARCH} == "i386"
# This package seems to be confused by i386 + AVX2/AVX512,
# and tries to use 64-bit assembly. This is a quick working fix.
# Note: "portable" here seems to mean "windows compiler friendly
# assembly syntax".
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PORTABLE_TARGET=ON
.endif

.include "../../devel/cmake/build.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
