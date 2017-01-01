# $NetBSD: Makefile,v 1.28 2017/01/01 14:43:27 wiz Exp $

DISTNAME=	pyPgSQL-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	9
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pypgsql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypgsql.sourceforge.net/
COMMENT=	Python DB-API 2.0 compliant interface to PostgreSQL

WRKSRC=		${WRKDIR}/pypgsql
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-mxDateTime

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
