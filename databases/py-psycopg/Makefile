# $NetBSD: Makefile,v 1.18 2005/01/24 16:59:42 seb Exp $
#

DISTNAME=	psycopg-1.1.14
PKGNAME=	${PYPKGPREFIX}-psycopg-1.1.14
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://initd.org/software/psycopg
COMMENT=	PostgreSQL database adapter for Python

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-python=${PYTHONBIN}
CONFIGURE_ARGS+= \
 --with-postgres-includes=${PGSQL_PREFIX}/include/postgresql\
 --with-postgres-libraries=${PGSQL_PREFIX}/lib
BUILD_TARGET=	default
USE_BUILDLINK3=	yes

PYTHON_VERSIONS_ACCEPTED= 23 22 21
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
