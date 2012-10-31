# $NetBSD: Makefile,v 1.2 2012/10/31 11:19:29 asau Exp $
#

DISTNAME=	python-daemon-1.5.5
EGG_NAME=	python_daemon-1.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-daemon/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/python-daemon/
COMMENT=	Library to implement a well-behaved Unix daemon process
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.9:../../devel/py-lockfile

WRKSRC=		${WRKDIR}/python-daemon-1.5.5
USE_LANGUAGES=	# none

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	${WRKSRC}/daemon/version/version_info.py

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_runner.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
