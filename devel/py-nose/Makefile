# $NetBSD: Makefile,v 1.17 2021/10/09 12:50:45 wiz Exp $

DISTNAME=	nose-1.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nose/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://nose.readthedocs.io/
COMMENT=	Unittest-based testing framework for python
LICENSE=	gnu-lgpl-v2.1

# only needed for a plugin
#DEPENDS+=	${PYPKGPREFIX}-coverage>=3.0:../../devel/py-coverage

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

pre-test:
	${RUN} cd ${WRKSRC} && \
	${PYTHONBIN} setup.py build_tests

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/nosetests
	${MV} ${DESTDIR}${PREFIX}/man/man1/nosetests.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nosetests${PYVERSSUFFIX}.1

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} selftest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
