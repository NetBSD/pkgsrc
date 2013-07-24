# $NetBSD: Makefile,v 1.15 2013/07/24 10:54:14 drochner Exp $
#

DISTNAME=		SimPy-2.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=		cad math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=simpy/} \
			http://pypi.python.org/packages/source/S/SimPy/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://simpy.sourceforge.net/
COMMENT=		Discrete event simulation framework
LICENSE=		gnu-lgpl-v2.1

PYDISTUTILSPKG=	yes

TEST_ENV+=	PYTHONPATH=${WRKSRC:Q}/build/lib

# needs py-test (pkgsrc/devel/py-test)
#do-test:
#	${SETENV} ${TEST_ENV} ${PYTHONBIN} -c "import SimPy; SimPy.test()"

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
