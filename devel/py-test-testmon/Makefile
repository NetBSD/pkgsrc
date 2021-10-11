# $NetBSD: Makefile,v 1.9 2021/10/11 13:02:52 adam Exp $

DISTNAME=	pytest-testmon-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-testmon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tarpas/pytest-testmon
COMMENT=	Py.test plug-in which selects tests affected by recent changes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-coverage>=4.0.0:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-test>=5.0.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
