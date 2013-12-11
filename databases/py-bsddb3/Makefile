# $NetBSD: Makefile,v 1.47 2013/12/11 19:18:56 wiz Exp $

DISTNAME=	bsddb3-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/b/bsddb3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bsddb3/
COMMENT=	Python extension module for Berkeley DB 4 and 5
LICENSE=	modified-bsd

BDB_ACCEPTED=		db4 db5

PYSETUPBUILDARGS=	--berkeley-db=${BDBBASE}
PYSETUPINSTALLARGS=	--berkeley-db=${BDBBASE}
PYSETUPBUILDARGS+=	--berkeley-db-incdir=${BDBBASE}/include/${BDB_TYPE}
PYSETUPINSTALLARGS+=	--berkeley-db-incdir=${BDBBASE}/include/${BDB_TYPE}

PYTHON_VERSIONS_INCLUDE_3X=	yes

REPLACE_PYTHON=		Lib/bsddb/dbshelve.py
REPLACE_PYTHON+=	Lib3/bsddb/dbshelve.py
REPLACE_PYTHON+=	Lib/bsddb/test/test_dbtables.py
REPLACE_PYTHON+=	Lib3/bsddb/test/test_dbtables.py

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
