# $NetBSD: Makefile,v 1.20 2022/01/05 15:41:06 wiz Exp $

DISTNAME=	nose-1.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nose/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://nose.readthedocs.io/
COMMENT=	Unittest-based testing framework for python
LICENSE=	gnu-lgpl-v2.1

# only needed for a plugin
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=3.0:../../devel/py-coverage

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/nosetests ${DESTDIR}${PREFIX}/bin/nosetests-${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/man/man1/nosetests.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nosetests${PYVERSSUFFIX}.1

.include "../../lang/python/egg.mk"

.if ${PYPKGPREFIX} == "py27"
# only work with python 2.x
do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} selftest.py
.else
pre-build:
	cd ${WRKSRC} && 2to3-${PYVERSSUFFIX} -w --no-diffs nose
.endif

.include "../../mk/bsd.pkg.mk"
