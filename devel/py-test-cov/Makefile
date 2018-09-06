# $NetBSD: Makefile,v 1.7 2018/09/06 14:10:28 adam Exp $

DISTNAME=	pytest-cov-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-cov/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-cov
COMMENT=	Pytest plugin for measuring coverage
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-coverage>=4.4:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-test>=2.9:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
