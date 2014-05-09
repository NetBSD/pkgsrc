# $NetBSD: Makefile,v 1.6 2014/05/09 07:37:00 wiz Exp $

DISTNAME=		buildbot-0.8.8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=		${DISTNAME}
CATEGORIES=		devel net python
MASTER_SITES=		http://buildbot.googlecode.com/files/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://buildbot.net/
COMMENT=		Continuous integration system
LICENSE=		gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-migrate-[0-9]*:../../databases/py-sqlalchemy-migrate
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-twisted, py-sqlite2, py-sqlalchemy-migrate

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
