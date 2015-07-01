# $NetBSD: Makefile,v 1.30 2015/07/01 09:59:06 wiz Exp $

DISTNAME=	psycopg2-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/psycopg/tarballs/PSYCOPG-2-6/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://initd.org/psycopg/
COMMENT=	PostgreSQL database adapter for Python
LICENSE=	gnu-lgpl-v3

REPLACE_PYTHON+=		tests/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
