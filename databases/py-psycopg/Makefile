# $NetBSD: Makefile,v 1.30 2008/04/26 15:36:22 joerg Exp $
#

DISTNAME=	psycopg-1.1.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://initd.org/projects/psycopg1/
COMMENT=	PostgreSQL database adapter for Python

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-python=${PYTHONBIN:Q}
CONFIGURE_ARGS+= \
 --with-postgres-includes=${PGSQL_PREFIX}/include/postgresql\
 --with-postgres-libraries=${PGSQL_PREFIX}/lib
BUILD_TARGET=	default

PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	25 24 23 21

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
