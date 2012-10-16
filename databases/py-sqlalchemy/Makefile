# $NetBSD: Makefile,v 1.6 2012/10/16 06:48:15 wiz Exp $

SQLALCHEMYVERS=	0.6.9
DISTNAME=	SQLAlchemy-${SQLALCHEMYVERS}
PKGNAME=	${PYPKGPREFIX}-sqlalchemy-${SQLALCHEMYVERS}
EGG_NAME=	${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sqlalchemy/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper
LICENSE=	mit

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "options.mk"

PLIST_SUBST+=		SQLALCHEMYVERS=${SQLALCHEMYVERS:Q}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
