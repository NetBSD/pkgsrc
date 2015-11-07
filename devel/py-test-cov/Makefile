# $NetBSD: Makefile,v 1.1 2015/11/07 19:03:04 wiz Exp $

DISTNAME=	pytest-cov-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-cov/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pytest-cov
COMMENT=	Pytest plugin for measuring coverage
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-coverage>=3.7.1:../../devel/py-coverage

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
