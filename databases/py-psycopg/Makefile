# $NetBSD: Makefile,v 1.14 2004/07/22 18:00:37 drochner Exp $
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
 --with-postgres-includes=${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql\
 --with-postgres-libraries=${BUILDLINK_PREFIX.postgresql-lib}/lib
ALL_TARGET=	default
USE_BUILDLINK3=	yes

PYTHON_VERSIONS_ACCEPTED= 23pth 22pth 21pth
PY_PATCHPLIST=	yes

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
