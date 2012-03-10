# $NetBSD: Makefile,v 1.13 2012/03/10 19:47:24 wiz Exp $
#

DISTNAME=		Pyro4-4.12
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://pypi.python.org/packages/source/P/Pyro4/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pyro.sourceforge.net/
COMMENT=		Distributed Object Technology system in Python
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	24

# only needed for test
#DEPENDS+= ${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
#DEPENDS+= ${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
do-test:
	cd ${WRKSRC}/tests; ${PYTHONBIN} run_suite.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
