# $NetBSD: Makefile,v 1.11 2022/01/04 20:53:43 wiz Exp $

DISTNAME=	pytest-testmon-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-testmon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tarpas/pytest-testmon
COMMENT=	Selects tests affected by changed files and methods
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-coverage>=4.0.0:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-test>=5.0.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
