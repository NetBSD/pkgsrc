# $NetBSD: Makefile,v 1.7 2015/06/26 16:13:51 rodent Exp $

DISTNAME=	python-sql-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-sql/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://code.google.com/p/python-sql/
COMMENT=	Python library to write SQL queries
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	sql/aggregate.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
