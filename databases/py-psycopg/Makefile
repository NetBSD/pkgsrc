# $NetBSD: Makefile,v 1.1.1.1 2002/10/25 14:17:24 drochner Exp $
#

DISTNAME=	psycopg-1.0.13
PKGNAME=	${PYPKGPREFIX}-psycopg-1.0.13
CATEGORIES=	databases
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://initd.org/software/psycopg
COMMENT=	PostgreSQL database adapter for Python

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-python=${PYTHONBIN}
CONFIGURE_ARGS+= \
 --with-postgres-includes=${BUILDLINK_PREFIX.postgresql-lib}/include/pgsql \
 --with-postgres-libraries=${BUILDLINK_PREFIX.postgresql-lib}/lib
# XXX ${PYSITELIB}/... doesn't get transformed by buildlink2
CONFIGURE_ARGS+= --with-mxdatetime-includes=${BUILDLINK_DIR}/include
ALL_TARGET=	default
USE_BUILDLINK2=	yes

PYTHON_VERSIONS_ACCEPTED= 21pth 22pth
PY_PATCHPLIST=	yes

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
