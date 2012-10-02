# $NetBSD: Makefile,v 1.22 2012/10/02 21:25:48 asau Exp $
#

DISTNAME=	pyPgSQL-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	7
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pypgsql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypgsql.sourceforge.net/
COMMENT=	Python DB-API 2.0 compliant interface to PostgreSQL

WRKSRC=		${WRKDIR}/pypgsql
PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
