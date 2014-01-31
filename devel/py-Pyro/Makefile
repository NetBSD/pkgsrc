# $NetBSD: Makefile,v 1.18 2014/01/31 11:27:14 wiz Exp $

DISTNAME=		Pyro4-4.22
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://pypi.python.org/packages/source/P/Pyro4/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pyro.sourceforge.net/
COMMENT=		Distributed Object Technology system in Python
LICENSE=		mit

DEPENDS+= ${PYPKGPREFIX}-serpent-[0-9]*:../../devel/py-serpent

# only needed for test
#DEPENDS+= ${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
#PYTHON_VERSIONED_DEPENDENCIES=unittest2
#.include "../../lang/python/versioned_dependencies.mk"
#DEPENDS+= ${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
do-test:
	cd ${WRKSRC}/tests; ${PYTHONBIN} run_suite.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
