# $NetBSD: Makefile,v 1.5 2012/08/16 15:07:42 drochner Exp $
#

DISTNAME=	nose-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
#MASTER_SITES=	http://python-nose.googlecode.com/files/
#MASTER_SITES=	http://somethingaboutorange.com/mrl/projects/nose/
MASTER_SITES=	http://pypi.python.org/packages/source/n/nose/
EXTRACT_USING=	gtar

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/python-nose/
COMMENT=	Unittest-based testing framework for python
LICENSE=	gnu-lgpl-v2.1

# only needed for a plugin
#DEPENDS+=	${PYPKGPREFIX}-coverage>=3.0:../../devel/py-coverage

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCLUDE_3X= yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/nosetests.1 ${WRKSRC}/nosetests${PYVERSSUFFIX}.1

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} selftest.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
