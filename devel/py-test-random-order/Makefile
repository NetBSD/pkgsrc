# $NetBSD: Makefile,v 1.1 2020/01/29 21:43:02 adam Exp $

DISTNAME=	pytest-random-order-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-random-order/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jbasko/pytest-random-order
COMMENT=	Randomise the order in which pytest tests are run
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=3.0.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
