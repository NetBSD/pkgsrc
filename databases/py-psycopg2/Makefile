# $NetBSD: Makefile,v 1.34 2017/03/05 14:19:07 wiz Exp $

DISTNAME=	psycopg2-2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/psycopg/tarballs/PSYCOPG-2-7/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://initd.org/psycopg/
COMMENT=	PostgreSQL database adapter for Python
LICENSE=	gnu-lgpl-v3

REPLACE_PYTHON+=		tests/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
