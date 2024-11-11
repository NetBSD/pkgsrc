# $NetBSD: Makefile,v 1.3 2024/11/11 07:28:23 wiz Exp $

DISTNAME=	semver-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/semver/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/python-semver/python-semver
COMMENT=	Python package to work with Semantic Versioning
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pysemver ${DESTDIR}${PREFIX}/bin/pysemver-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
