# $NetBSD: Makefile,v 1.6 2026/09/24 11:13:09 adam Exp $

DISTNAME=	semver-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/semver/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/python-semver/python-semver
COMMENT=	Python package to work with Semantic Versioning
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pysemver

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
