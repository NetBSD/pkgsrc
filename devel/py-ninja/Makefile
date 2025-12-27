# $NetBSD: Makefile,v 1.7 2025/12/27 22:17:02 adam Exp $

DISTNAME=	ninja-1.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ninja/}

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

# add symlink where the normal build system would put the freshly-compiled ninja binary
post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/ninja/data/bin && ${LN} -s ${PREFIX}/bin/ninja .

.include "../../devel/googletest/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
