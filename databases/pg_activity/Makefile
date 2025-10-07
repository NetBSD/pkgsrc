# $NetBSD: Makefile,v 1.1 2025/10/07 17:20:58 gdt Exp $

DISTNAME=	pg_activity-3.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pg_activity/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://pypi.org/project/pg_activity/
COMMENT=	Command line tool for PostgreSQL server activity monitoring
LICENSE=	postgresql-license

DEPENDS+=	${PYPKGPREFIX}-attrs>=17.4:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-blessed>=1.15.0:../../devel/py-blessed
DEPENDS+=	${PYPKGPREFIX}-humanize>=0.5.1:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-psutil>=2.0.0:../../sysutils/py-psutil
# prefers psycopg3 but not in pkgsrc
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.9":../../databases/py-psycopg2

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
