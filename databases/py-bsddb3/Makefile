# $NetBSD: Makefile,v 1.29 2008/05/15 18:16:17 drochner Exp $
#

DISTNAME=	bsddb3-4.6.4
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

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
PYTHON_VERSIONS_INCOMPATIBLE=	15 21
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} test.py

.include "../../databases/db4/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
