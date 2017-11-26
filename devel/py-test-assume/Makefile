# $NetBSD: Makefile,v 1.1 2017/11/26 17:10:46 adam Exp $

DISTNAME=	pytest-assume-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-assume/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astraw38/pytest-assume
COMMENT=	Py.test plugin that allows multiple failures per test
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=2.7:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
