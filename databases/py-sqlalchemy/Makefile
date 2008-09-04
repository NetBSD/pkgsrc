# $NetBSD: Makefile,v 1.1.1.1 2008/09/04 20:42:28 tonnerre Exp $

SQLALCHEMYVERS=	0.4.7p1
DISTNAME=	SQLAlchemy-${SQLALCHEMYVERS}
PKGNAME=	${PYPKGPREFIX}-sqlalchemy-${SQLALCHEMYVERS}
EGG_NAME=	${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sqlalchemy/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "options.mk"

PLIST_SUBST+=		SQLALCHEMYVERS=${SQLALCHEMYVERS:Q}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
