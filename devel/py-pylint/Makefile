# $NetBSD: Makefile,v 1.4 2014/12/06 11:00:52 obache Exp $

DISTNAME=	pylint-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pylint/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://www.logilab.org/project/pylint
COMMENT=	Python code static checker
LICENSE=    	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
DEPENDS+=	${PYPKGPREFIX}-astroid>=1.0.1:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-logilab-common>=0.53.0:../../devel/py-logilab-common

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-mxDateTime via py-logilab-common

USE_LANGUAGES=	# none

DOCDIR=			${PREFIX}/share/doc/pylint
INSTALLATION_DIRS=	${DOCDIR} ${PKGMANDIR}/man1
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

REPLACE_PYTHON+=	__main__.py test/input/noext

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/epylint \
		${DESTDIR}${PREFIX}/bin/epylint${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/pylint \
		${DESTDIR}${PREFIX}/bin/pylint${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/pylint-gui \
		${DESTDIR}${PREFIX}/bin/pylint-gui${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/pyreverse \
		${DESTDIR}${PREFIX}/bin/pyreverse${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/symilar \
		${DESTDIR}${PREFIX}/bin/symilar${PYVERSSUFFIX}
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
