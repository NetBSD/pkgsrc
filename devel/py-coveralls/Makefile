# $NetBSD: Makefile,v 1.5 2025/09/28 19:03:29 wiz Exp $

DISTNAME=	coveralls-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/python-coveralls
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} coveralls coveralls-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
