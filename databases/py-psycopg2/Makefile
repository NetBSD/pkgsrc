# $NetBSD: Makefile,v 1.58 2023/10/04 08:19:57 adam Exp $

DISTNAME=	psycopg2-2.9.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psycopg2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.psycopg.org/
COMMENT=	PostgreSQL database adapter for Python
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
