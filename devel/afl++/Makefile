# $NetBSD: Makefile,v 1.8 2026/01/03 22:16:36 wiz Exp $

DISTNAME=	AFLplusplus-4.35c
PKGNAME=	${DISTNAME:C/AFLplusplus/afl++/}
GITHUB_PROJECT=	AFLplusplus
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AFLplusplus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AFLplusplus/AFLplusplus/
COMMENT=	American Fuzzy Lop ++, a fuzzing tool for finding bugs by random input
LICENSE=	apache-2.0

TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

PYTHON_INCLUDE_CMD=	python${PYVERSSUFFIX}-config --includes
PYTHON_VERSION_CMD=	python${PYVERSSUFFIX} --version
PYTHON_LIB_CMD=		python${PYVERSSUFFIX}-config --libs --embed --ldflags
REPLACE_PYTHON+=	afl-cmin.py

MAKE_FLAGS+=	PYTHON_INCLUDE=${PYTHON_INCLUDE_CMD:sh:Q}
MAKE_FLAGS+=	PYTHON_VERSION=${PYTHON_VERSION_CMD:sh:Q}
MAKE_FLAGS+=	PYTHON_LIB=${PYTHON_LIB_CMD:sh:Q}

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run gmake
REPLACE_BASH+=	afl-cmin
REPLACE_BASH+=	afl-cmin.bash
REPLACE_BASH+=	afl-persistent-config
MAKE_FILE=	GNUmakefile

.include "../../mk/bsd.prefs.mk"

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LDFLAGS+=	-lexecinfo
.endif

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
