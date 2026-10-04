# $NetBSD: Makefile,v 1.1 2026/10/04 16:59:30 wiz Exp $

DISTNAME=	pytest_remaster-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_remaster/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Pierre-Sassoulas/pytest-remaster
COMMENT=	Pytest plugin for golden master (characterisation) testing
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=82:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
