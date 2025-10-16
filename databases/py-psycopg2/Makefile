# $NetBSD: Makefile,v 1.64 2025/10/16 14:44:23 adam Exp $

DISTNAME=	psycopg2-2.9.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psycopg2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.psycopg.org/
COMMENT=	PostgreSQL database adapter for Python
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
