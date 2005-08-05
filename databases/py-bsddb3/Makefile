# $NetBSD: Makefile,v 1.15 2005/08/05 18:21:04 drochner Exp $
#

DISTNAME=	bsddb3-4.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pybsddb/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pybsddb.sourceforge.net/
COMMENT=	Python extension module for Berkeley DB 4

PYSETUPBUILDARGS=	--berkeley-db=${BUILDLINK_PREFIX.db4}
PYSETUPINSTALLARGS=	--berkeley-db=${BUILDLINK_PREFIX.db4}

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

BUILDLINK_DEPENDS.db4+=		db4>=4.2.52

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
PYTHON_VERSIONS_ACCEPTED=	24 23 22
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} test.py

.include "../../databases/db4/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
