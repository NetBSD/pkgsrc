# $NetBSD: Makefile,v 1.3 2019/01/08 09:10:11 adam Exp $

DISTNAME=	pytest-asyncio-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-asyncio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-asyncio
COMMENT=	Pytest support for asyncio
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-test>=3.0.6:../../devel/py-test

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 35
DEPENDS+=	${PYPKGPREFIX}-async_generator>=1.3:../../devel/py-async_generator
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
