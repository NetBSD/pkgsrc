# $NetBSD: Makefile,v 1.5 2024/12/16 05:45:04 adam Exp $

DISTNAME=	ninja-1.11.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ninja/}
DISTFILES=	${DEFAULT_DISTFILES} ninja-1.11.1.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scikit-build/ninja-python-distributions
COMMENT=	Python bindings for the ninja build tool
LICENSE=	apache-2.0

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core-[0-9]*:../../devel/py-scikit-build-core
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build
TEST_DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=2.0:../../devel/py-importlib-metadata
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PYSITELIB}/ninja/data/bin

# avoid building ninja again, just provide source code so CMake is happy
post-extract:
	cd ${WRKSRC} && ${LN} -s ../ninja-1.11.1 Ninja-src

# add symlink where the normal build system would put the freshly-compiled ninja binary
post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/ninja/data/bin && ${LN} -s ${PREFIX}/bin/ninja .

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
