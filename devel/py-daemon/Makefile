# $NetBSD: Makefile,v 1.4 2014/05/09 07:37:00 wiz Exp $

DISTNAME=	python-daemon-1.6
EGG_NAME=	${DISTNAME:S/-/_/}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-daemon/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/python-daemon/
COMMENT=	Library to implement a well-behaved Unix daemon process
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.9:../../devel/py-lockfile

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.6

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	${WRKSRC}/daemon/version/version_info.py

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_runner.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
