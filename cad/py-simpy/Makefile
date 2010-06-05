# $NetBSD: Makefile,v 1.10 2010/06/05 04:38:46 obache Exp $
#

DISTNAME=		SimPy-2.1.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=		cad math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=simpy/} \
			http://pypi.python.org/packages/source/S/SimPy/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://simpy.sourceforge.net/
COMMENT=		Discrete event simulation framework
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

TEST_ENV+=	PYTHONPATH=${WRKSRC:Q}/build/lib

do-test:
	${RUN} cd ${WRKSRC}; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} SimPy/testSimPy.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
