# $NetBSD: Makefile,v 1.27 2026/02/23 09:56:38 adam Exp $

DISTNAME=	stevedore-5.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stevedore/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dreamhost/stevedore
COMMENT=	Manage dynamic plugins for Python applications
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr>=6.1.1:../../devel/py-pbr
TEST_DEPENDS+=	${PYPKGPREFIX}-bandit>=1.6.0:../../security/py-bandit
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.2.0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
