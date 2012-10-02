# $NetBSD: Makefile,v 1.45 2012/10/02 21:25:48 asau Exp $

DISTNAME=	bsddb3-5.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/b/bsddb3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bsddb3/
COMMENT=	Python extension module for Berkeley DB 4
LICENSE=	mit

BDB_ACCEPTED=		db4 db5

PYSETUPBUILDARGS=	--berkeley-db=${BDBBASE}
PYSETUPINSTALLARGS=	--berkeley-db=${BDBBASE}

PYDISTUTILSPKG=	yes

REPLACE_PYTHON=		Lib/bsddb/dbshelve.py
REPLACE_PYTHON+=	Lib3/bsddb/dbshelve.py

SUBST_CLASSES+=		bdb
SUBST_STAGE.bdb=	pre-configure
SUBST_FILES.bdb=	${WRKSRC}/setup2.py
SUBST_SED.bdb=		-e "s,dblib = 'db',dblib = '${BDB_TYPE}',g"

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
