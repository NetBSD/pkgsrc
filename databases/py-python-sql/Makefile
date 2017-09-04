# $NetBSD: Makefile,v 1.9 2017/09/04 18:55:07 wiz Exp $

DISTNAME=	python-sql-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-sql/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://python-sql.tryton.org/
COMMENT=	Python library to write SQL queries
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	sql/aggregate.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
