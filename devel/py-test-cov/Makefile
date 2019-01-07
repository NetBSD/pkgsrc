# $NetBSD: Makefile,v 1.8 2019/01/07 08:43:55 adam Exp $

DISTNAME=	pytest-cov-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-cov/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-cov
COMMENT=	Pytest plugin for measuring coverage
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-coverage>=4.4:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-test>=3.6:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
