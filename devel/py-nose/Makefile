# $NetBSD: Makefile,v 1.21 2022/08/24 09:25:56 wiz Exp $

DISTNAME=	nose-1.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nose/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://nose.readthedocs.io/
COMMENT=	Unittest-based testing framework for python
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes
# only needed for a plugin
PYTHON_VERSIONED_DEPENDENCIES+=	coverage:test

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

.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
