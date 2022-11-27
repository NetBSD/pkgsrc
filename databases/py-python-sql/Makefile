# $NetBSD: Makefile,v 1.15 2022/11/27 09:26:40 adam Exp $

DISTNAME=	python-sql-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-sql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-sql.tryton.org/
COMMENT=	Python library to write SQL queries
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	sql/aggregate.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
