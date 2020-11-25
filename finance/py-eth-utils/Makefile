# $NetBSD: Makefile,v 1.4 2020/11/25 11:13:19 nia Exp $

DISTNAME=	eth-utils-1.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ethereum/}
GITHUB_PROJECT=	eth-utils
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/ethereum/eth-utils
COMMENT=	Common utility functions for ethereum codebases
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-twine-[0-9]*:../../net/py-twine
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
#BUILD_DEPENDS+=	# TODO: towncrier>=19.2.0,<20
BUILD_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-isort-[0-9]*:../../devel/py-isort
BUILD_DEPENDS+=	${PYPKGPREFIX}-mypy-[0-9]*:../../lang/py-mypy
#BUILD_DEPENDS+=	# TODO: pytest>=3.4.1,<4.0.0
BUILD_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
#BUILD_DEPENDS+=	# TODO: pytest>=3.4.1,<4.0.0
#BUILD_DEPENDS+=	# TODO: pytest-pythonpath>=0.3,<1.0
BUILD_DEPENDS+=	${PYPKGPREFIX}-bump2version-[0-9]*:../../devel/py-bump2version
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-eth-hash-[0-9]*:../../finance/py-eth-hash
DEPENDS+=	${PYPKGPREFIX}-eth-typing-[0-9]*:../../finance/py-eth-typing
DEPENDS+=	${PYPKGPREFIX}-toolz-[0-9]*:../../devel/py-toolz
DEPENDS+=	${PYPKGPREFIX}-cytoolz-[0-9]*:../../devel/py-cytoolz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-bump2version py-eth-typing
PYTHON_VERSIONS_INCOMPATIBLE+=	36 # py-eth-hash-0.2.0nb1 py-eth-typing

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
