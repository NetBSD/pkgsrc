# $NetBSD: Makefile,v 1.11 2014/01/20 22:27:00 wiz Exp $

DISTNAME=	SQLAlchemy-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
EGG_NAME=	${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/S/SQLAlchemy/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose>=0.11:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock

REPLACE_PYTHON=	lib/sqlalchemy/testing/runner.py

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
