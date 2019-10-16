# $NetBSD: Makefile,v 1.10 2019/10/16 16:41:16 adam Exp $

DISTNAME=	pytest-cov-2.8.1
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
