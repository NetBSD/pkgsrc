# $NetBSD: Makefile,v 1.2 2014/02/01 14:10:47 rodent Exp $

DISTNAME=	python-sql-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-sql/
FETCH_USING=	curl

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://code.google.com/p/python-sql/
COMMENT=	Python library to write SQL queries
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	sql/aggregate.py
EGG_NAME=		${DISTNAME:S/-/_/1}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
