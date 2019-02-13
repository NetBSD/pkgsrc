# $NetBSD: Makefile,v 1.3 2019/02/13 15:41:30 adam Exp $

DISTNAME=	pytest-assume-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-assume/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astraw38/pytest-assume
COMMENT=	Py.test plugin that allows multiple failures per test
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=2.7:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
