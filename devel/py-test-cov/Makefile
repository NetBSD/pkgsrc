# $NetBSD: Makefile,v 1.5 2017/05/17 11:26:25 wiz Exp $

DISTNAME=	pytest-cov-2.5.1
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
