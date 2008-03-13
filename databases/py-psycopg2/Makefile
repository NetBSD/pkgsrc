# $NetBSD: Makefile,v 1.6 2008/03/13 17:38:48 joerg Exp $
#

DISTNAME=	psycopg2-2.0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://initd.org/projects/psycopg2/
COMMENT=	PostgreSQL database adapter for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED= 24 23

.include "../../lang/python/extension.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
