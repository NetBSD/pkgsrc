# $NetBSD: Makefile,v 1.1.1.1 2006/07/12 16:34:39 joerg Exp $
#

DISTNAME=	psycopg2-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://initd.org/software/psycopg
COMMENT=	PostgreSQL database adapter for Python

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED= 24 23

.include "../../lang/python/extension.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
