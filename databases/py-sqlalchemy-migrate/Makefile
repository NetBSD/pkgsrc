# $NetBSD: Makefile,v 1.3 2012/10/04 07:05:53 wiz Exp $

DISTNAME=	sqlalchemy-migrate-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	sqlalchemy_migrate-0.7.2
CATEGORIES=	databases python
MASTER_SITES=	http://sqlalchemy-migrate.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sqlalchemy-migrate/
COMMENT=	Schema migration tool for SQLAlchemy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Tempita>=0.4:../../textproc/py-Tempita
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.6<0.7:../../databases/py-sqlalchemy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
