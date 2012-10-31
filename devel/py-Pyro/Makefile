# $NetBSD: Makefile,v 1.15 2012/10/31 11:19:27 asau Exp $
#

DISTNAME=		Pyro4-4.12
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://pypi.python.org/packages/source/P/Pyro4/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pyro.sourceforge.net/
COMMENT=		Distributed Object Technology system in Python
LICENSE=		mit

# only needed for test
#DEPENDS+= ${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
#DEPENDS+= ${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
do-test:
	cd ${WRKSRC}/tests; ${PYTHONBIN} run_suite.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
