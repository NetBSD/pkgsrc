# $NetBSD: Makefile,v 1.8 2022/02/01 10:21:16 wiz Exp $

DISTNAME=	clickclick-20.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/clickclick/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/hjacobs/python-clickclick
COMMENT=	Click utility functions
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-click>=4.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
# tests are not included in pypi distfile
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
