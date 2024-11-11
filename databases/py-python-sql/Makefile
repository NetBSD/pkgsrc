# $NetBSD: Makefile,v 1.21 2024/11/11 07:27:58 wiz Exp $

DISTNAME=	python_sql-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-sql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-sql.tryton.org/
COMMENT=	Python library to write SQL queries
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	sql/aggregate.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
