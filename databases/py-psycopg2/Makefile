# $NetBSD: Makefile,v 1.43 2018/11/09 21:26:29 adam Exp $

DISTNAME=	psycopg2-2.7.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/psycopg/tarballs/PSYCOPG-2-7/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://initd.org/psycopg/
COMMENT=	PostgreSQL database adapter for Python
LICENSE=	gnu-lgpl-v3

.include "../../lang/python/egg.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
