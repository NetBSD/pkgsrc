# $NetBSD: Makefile,v 1.12 2004/07/06 22:57:06 wiz Exp $
#

DISTNAME=	psycopg-1.1.11
PKGNAME=	${PYPKGPREFIX}-psycopg-1.1.11
CATEGORIES=	databases
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://initd.org/software/psycopg
COMMENT=	PostgreSQL database adapter for Python

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-python=${PYTHONBIN}
CONFIGURE_ARGS+= \
 --with-postgres-includes=${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql\
 --with-postgres-libraries=${BUILDLINK_PREFIX.postgresql-lib}/lib
# XXX: following comment still true for buildlink3?
# XXX ${PYSITELIB}/... doesn't get transformed by buildlink2
CONFIGURE_ARGS+= --with-mxdatetime-includes=${BUILDLINK_DIR}/include
ALL_TARGET=	default
USE_BUILDLINK3=	yes

PYTHON_VERSIONS_ACCEPTED= 21pth 22pth
PY_PATCHPLIST=	yes

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
