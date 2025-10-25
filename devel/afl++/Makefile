# $NetBSD: Makefile,v 1.7 2025/10/25 13:57:40 kikadf Exp $

DISTNAME=	AFLplusplus-4.34c
PKGNAME=	${DISTNAME:C/AFLplusplus/afl++/}
GITHUB_PROJECT=	AFLplusplus
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AFLplusplus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AFLplusplus/AFLplusplus/
COMMENT=	American Fuzzy Lop ++, a fuzzing tool for finding bugs by random input
LICENSE=	apache-2.0

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
