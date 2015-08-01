# $NetBSD: Makefile,v 1.15 2015/08/01 09:30:52 adam Exp $

DISTNAME=	SQLAlchemy-1.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/S/SQLAlchemy/

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
