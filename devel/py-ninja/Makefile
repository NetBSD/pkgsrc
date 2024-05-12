# $NetBSD: Makefile,v 1.1 2024/05/12 17:45:15 wiz Exp $

DISTNAME=	ninja-1.11.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ninja/}
DISTFILES=	${DEFAULT_DISTFILES} ninja-1.11.1.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/ninja/
COMMENT=	Python bindings for the ninja build tool
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-[0-9]*:../../devel/py-scikit-build
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build
TEST_DEPENDS+=	${PYPKGPREFIX}-path-[0-9]*:../../devel/py-path
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-virtualenv-[0-9]*:../../devel/py-test-virtualenv

USE_LANGUAGES+=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALLATION_DIRS+=	${PYSITELIB}/ninja/data/bin

# avoid building ninja again, just provide source code so CMake is happy
post-extract:
	cd ${WRKSRC} && ${LN} -s ../ninja-1.11.1 Ninja-src

# add symlink where the normal build system would put the freshly-compiled ninja binary
post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/ninja
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/ninja/data/bin && ${LN} -s ${PREFIX}/bin/ninja .

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
