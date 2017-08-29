# $NetBSD: Makefile,v 1.1 2017/08/29 06:55:55 wiz Exp $

DISTNAME=	pathlib-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
