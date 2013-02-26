# $NetBSD: Makefile,v 1.7 2013/02/26 10:24:27 joerg Exp $
#

DISTNAME=	nose-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
#MASTER_SITES=	http://python-nose.googlecode.com/files/
#MASTER_SITES=	http://somethingaboutorange.com/mrl/projects/nose/
MASTER_SITES=	http://pypi.python.org/packages/source/n/nose/
EXTRACT_USING=	bsdtar

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/python-nose/
COMMENT=	Unittest-based testing framework for python
LICENSE=	gnu-lgpl-v2.1

# only needed for a plugin
#DEPENDS+=	${PYPKGPREFIX}-coverage>=3.0:../../devel/py-coverage

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCLUDE_3X= yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/nosetests.1 ${WRKSRC}/nosetests${PYVERSSUFFIX}.1

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} selftest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
