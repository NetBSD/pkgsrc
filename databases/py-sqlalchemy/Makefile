# $NetBSD: Makefile,v 1.19 2016/06/02 10:29:03 adam Exp $

DISTNAME=	SQLAlchemy-1.0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose>=0.11:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock

REPLACE_PYTHON=	lib/sqlalchemy/testing/runner.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
