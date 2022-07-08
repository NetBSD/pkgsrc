# $NetBSD: Makefile,v 1.16 2022/07/08 14:12:12 wiz Exp $

DISTNAME=	requests-toolbelt-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-toolbelt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://toolbelt.readthedocs.io/
COMMENT=	Utility belt for advanced users of python-requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0<3.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-betamax-[0-9]*:../../www/py-betamax
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
