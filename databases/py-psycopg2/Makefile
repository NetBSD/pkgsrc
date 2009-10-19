# $NetBSD: Makefile,v 1.9 2009/10/19 10:54:47 joerg Exp $
#

DISTNAME=	psycopg2-2.0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://initd.org/projects/psycopg2/
COMMENT=	PostgreSQL database adapter for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
