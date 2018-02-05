# $NetBSD: Makefile,v 1.1 2018/02/05 16:28:49 adam Exp $

DISTNAME=	pytest-asyncio-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-asyncio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-asyncio
COMMENT=	Pytest support for asyncio
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-async_generator>=1.3:../../devel/py-async_generator
DEPENDS+=	${PYPKGPREFIX}-test>=3.0.6:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
