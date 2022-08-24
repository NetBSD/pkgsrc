# $NetBSD: Makefile,v 1.2 2022/08/24 10:18:04 wiz Exp $

DISTNAME=	expiringdict-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/expiringdict/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mailgun.com/
COMMENT=	Dictionary with auto-expiring values for caching purposes
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-dill>=0:../../textproc/py-dill
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-coveralls>=3:../../devel/py-coveralls
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=0:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
