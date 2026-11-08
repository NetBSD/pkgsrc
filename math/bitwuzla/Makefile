# $NetBSD: Makefile,v 1.1 2026/11/08 17:36:17 alnsn Exp $

DISTNAME=	bitwuzla-0.9.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=bitwuzla/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitwuzla.github.io/
COMMENT=	SMT solver for bit-vectors, floats, arrays and uninterpreted functions
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
USE_TOOLS+=		pkg-config

MESON_OUTPUT_DIR=	build

BUILDLINK_DEPMETHOD.cadical=	build
BUILDLINK_DEPMETHOD.symfpu=	build

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${TOOL_PYTHONBIN} ./configure.py \
		--prefix ${PREFIX} --shared --cadical --no-testing

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../math/cadical/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/symfpu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
