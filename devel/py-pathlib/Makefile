# $NetBSD: Makefile,v 1.2 2022/01/10 20:41:00 wiz Exp $

DISTNAME=	pathlib-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pathlib/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pathlib.readthedocs.org/
COMMENT=	Object-oriented filesystem paths
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # included in 3.4+

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_pathlib.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
