# $NetBSD: Makefile,v 1.20 2011/02/28 14:52:43 wiz Exp $
#

DISTNAME=	pyPgSQL-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	6
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pypgsql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypgsql.sourceforge.net/
COMMENT=	Python DB-API 2.0 compliant interface to PostgreSQL

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pypgsql
PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
