# $NetBSD: Makefile,v 1.7 2013/06/16 05:36:13 adam Exp $

DISTNAME=	SQLAlchemy-0.7.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
EGG_NAME=	${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/S/SQLAlchemy/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper
LICENSE=	mit

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
