# $NetBSD: Makefile,v 1.1.1.1 2003/09/09 13:46:24 recht Exp $
#

DISTNAME=	pyPgSQL-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
WRKSRC=		${WRKDIR}/pypgsql
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pypgsql/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://pypgsql.sourceforge.net/
COMMENT=	Python DB-API 2.0 compliant interface to PostgreSQL

USE_BUILDLINK2=	YES
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

post-install:
	${PYTHONBIN} -O ${LOCALBASE}/${PYLIB}/compileall.py \
		${LOCALBASE}/${PYSITELIB}/pyPgSQL

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
