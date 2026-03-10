# $NetBSD: Makefile,v 1.8 2026/03/10 14:11:54 adam Exp $

DISTNAME=	coveralls-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coveralls/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TheKevJames/coveralls-python
COMMENT=	Python interface to coveralls.io API
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-coverage>=6.1.1:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-requests>=1.0.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-typer>=0.12.0:../../devel/py-typer
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/python-coveralls
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} coveralls coveralls-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
