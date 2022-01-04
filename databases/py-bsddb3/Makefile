# $NetBSD: Makefile,v 1.60 2022/01/04 20:52:41 wiz Exp $

DISTNAME=	bsddb3-6.2.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bsddb3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jcea.es/programacion/pybsddb.htm
COMMENT=	Python bindings for Oracle Berkeley DB
LICENSE=	modified-bsd

BDB_ACCEPTED=	db6 db5 db4

PYSETUPBUILDARGS=	--berkeley-db=${BDBBASE}
PYSETUPINSTALLARGS=	--berkeley-db=${BDBBASE}
PYSETUPBUILDARGS+=	--berkeley-db-incdir=${BDBBASE}/include/${BDB_TYPE}
PYSETUPINSTALLARGS+=	--berkeley-db-incdir=${BDBBASE}/include/${BDB_TYPE}

REPLACE_PYTHON=		Lib/bsddb/dbshelve.py
REPLACE_PYTHON+=	Lib3/bsddb/dbshelve.py
REPLACE_PYTHON+=	Lib/bsddb/test/test_dbtables.py
REPLACE_PYTHON+=	Lib3/bsddb/test/test_dbtables.py

SUBST_CLASSES+=		bdb
SUBST_STAGE.bdb=	pre-configure
SUBST_FILES.bdb=	${WRKSRC}/setup2.py ${WRKSRC}/setup3.py
SUBST_SED.bdb=		-e "s,dblib = 'db',dblib = '${BDB_TYPE}',g"

MAKE_ENV+=		YES_I_HAVE_THE_RIGHT_TO_USE_THIS_BERKELEY_DB_VERSION=1

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
