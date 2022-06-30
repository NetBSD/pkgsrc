# $NetBSD: Makefile,v 1.6 2022/06/30 11:18:12 nia Exp $

DISTNAME=	cvise-2.4.0
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=marxin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/marxin/cvise
COMMENT=	Super-parallel Python port of the C-Reduce
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pebble-[0-9]*:../../devel/py-pebble
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
DEPENDS+=	unifdef-[0-9]*:../../devel/unifdef
.endif
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_CMAKE=	yes
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

USE_LANGUAGES=	c c++
USE_TOOLS+=	flex
#TEST_TARGET=	check

REPLACE_PYTHON+=	cvise.py
REPLACE_PYTHON+=	cvise-delta.py

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../lang/python/application.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
