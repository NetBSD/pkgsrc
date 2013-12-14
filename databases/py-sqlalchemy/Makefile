# $NetBSD: Makefile,v 1.10 2013/12/14 08:47:18 obache Exp $

DISTNAME=	SQLAlchemy-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
EGG_NAME=	${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/S/SQLAlchemy/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose>=0.11:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock

#PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
