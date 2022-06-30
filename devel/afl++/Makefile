# $NetBSD: Makefile,v 1.4 2022/06/30 11:18:10 nia Exp $

DISTNAME=	AFLplusplus-2.62c
PKGNAME=	${DISTNAME:C/AFLplusplus/afl++/}
PKGREVISION=	1
GITHUB_PROJECT=	AFLplusplus
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AFLplusplus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AFLplusplus/AFLplusplus/
COMMENT=	American Fuzzy Lop ++, a fuzzing tool for finding bugs by random input
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/pyversion.mk"
PYTHON_INCLUDE_CMD=	python${PYVERSSUFFIX}-config --includes
PYTHON_VERSION_CMD=	python${PYVERSSUFFIX} --version

.if ${PYVERSSUFFIX} < 38
PYTHON_LIB_CMD=	python${PYVERSSUFFIX}-config --ldflags
.else
PYTHON_LIB_CMD=	python${PYVERSSUFFIX}-config --libs --embed --ldflags
.endif

MAKE_FLAGS+=	PYTHON_INCLUDE=${PYTHON_INCLUDE_CMD:sh:Q}
MAKE_FLAGS+=	PYTHON_VERSION=${PYTHON_VERSION_CMD:sh:Q}
MAKE_FLAGS+=	PYTHON_LIB=${PYTHON_LIB_CMD:sh:Q}

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run gmake
REPLACE_SH+=	afl-plot
REPLACE_BASH+=	afl-cmin
REPLACE_BASH+=	afl-cmin.bash

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	amd64
.if ${MACHINE_ARCH} == "x86_64"
PLIST.amd64=	yes
.endif

.include "../../mk/bsd.pkg.mk"
