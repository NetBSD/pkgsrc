# $NetBSD: Makefile,v 1.6 2026/01/18 10:50:26 wiz Exp $

DISTNAME=	libfyaml-0.9.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pantoniou/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pantoniou/libfyaml
COMMENT=	Feature-complete YAML parser and emitter
LICENSE=	mit

USE_TOOLS+=	bash:test
TEST_TARGET=	test

PKGCONFIG_OVERRIDE+=	cmake/libfyaml.pc.in

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}

.include "../../devel/cmake/build.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
