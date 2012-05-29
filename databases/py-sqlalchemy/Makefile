# $NetBSD: Makefile,v 1.4 2012/05/29 13:22:28 wiz Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "options.mk"

PLIST_SUBST+=		SQLALCHEMYVERS=${SQLALCHEMYVERS:Q}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
