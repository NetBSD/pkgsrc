# $NetBSD: Makefile,v 1.9 2004/08/05 22:20:11 recht Exp $
#

DISTNAME=	pyPgSQL-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pypgsql/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://pypgsql.sourceforge.net/
COMMENT=	Python DB-API 2.0 compliant interface to PostgreSQL

WRKSRC=		${WRKDIR}/pypgsql
USE_BUILDLINK3=	YES
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
