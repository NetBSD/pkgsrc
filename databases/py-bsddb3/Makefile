# $NetBSD: Makefile,v 1.33 2009/01/07 21:15:49 wiz Exp $
#

DISTNAME=	bsddb3-4.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/b/bsddb3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bsddb3/
COMMENT=	Python extension module for Berkeley DB 4

PKG_DESTDIR_SUPPORT=	user-destdir

PYSETUPBUILDARGS=	--berkeley-db=${BUILDLINK_PREFIX.db4}
PYSETUPINSTALLARGS=	--berkeley-db=${BUILDLINK_PREFIX.db4}

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

REPLACE_PYTHON=		Lib/bsddb/dbshelve.py
REPLACE_PYTHON+=	Lib3/bsddb/dbshelve.py

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
PYTHON_VERSIONS_INCOMPATIBLE=	21
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} test.py

.include "../../databases/db4/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
