# $NetBSD: Makefile,v 1.7 2025/11/11 10:27:22 adam Exp $

DISTNAME=	coveralls-4.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/coveralls/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TheKevJames/coveralls-python
COMMENT=	Python interface to coveralls.io API
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-coverage>=6.1.1:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.1:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-requests>=1.0.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/python-coveralls
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} coveralls coveralls-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
