# $NetBSD: Makefile,v 1.1 2014/01/30 04:54:57 rodent Exp $

DISTNAME=	0.2
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME:S/_/-/1}
CATEGORIES=	databases python
MASTER_SITES=	http://python-sql.googlecode.com/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://python-sql.googlecode.com/archive/
COMMENT=	Python library to write SQL queries
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/python-sql-e8322fa5b114
USE_LANGUAGES=	# none

REPLACE_PYTHON+=	sql/aggregate.py
EGG_NAME=		python_sql-${DISTNAME}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
