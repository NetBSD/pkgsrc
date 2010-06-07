# $NetBSD: Makefile,v 1.39 2010/06/07 19:36:41 gls Exp $

DISTNAME=	bsddb3-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/b/bsddb3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bsddb3/
COMMENT=	Python extension module for Berkeley DB 4

PKG_DESTDIR_SUPPORT=	user-destdir

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

.include "../../mk/pthread.buildlink3.mk"

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} test.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
