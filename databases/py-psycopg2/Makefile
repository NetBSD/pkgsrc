# $NetBSD: Makefile,v 1.14 2011/04/15 13:28:26 adam Exp $

DISTNAME=	psycopg2-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/psycopg/tarballs/PSYCOPG-2-4/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://initd.org/psycopg/
COMMENT=	PostgreSQL database adapter for Python
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
