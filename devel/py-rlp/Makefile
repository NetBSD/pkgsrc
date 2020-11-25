# $NetBSD: Makefile,v 1.6 2020/11/25 11:13:18 nia Exp $

DISTNAME=	pyrlp-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ethereum/}
GITHUB_PROJECT=	pyrlp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/pyrlp
COMMENT=	Package for Recursive Length Prefix encoding and decoding
LICENSE=	mit

EGG_NAME=	rlp-1.2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-bump2version-[0-9]*:../../devel/py-bump2version
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
BUILD_DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython5
BUILD_DEPENDS+=	${PYPKGPREFIX}-twine-[0-9]*:../../net/py-twine
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
BUILD_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-watch>=4.1.0:../../devel/py-test-watch
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
DEPENDS+=	${PYPKGPREFIX}-eth-utils-[0-9]*:../../finance/py-eth-utils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-bump2version py-twine
PYTHON_VERSIONS_INCOMPATIBLE+=	36 # py-eth-utils

do-test:
	cd ${WRKSRC} && tox-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
