# $NetBSD: Makefile,v 1.1 2021/06/27 16:25:23 wiz Exp $

DISTNAME=	magic-wormhole-transit-relay-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/magic-wormhole-transit-relay/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magic-wormhole/magic-wormhole-transit-relay
COMMENT=	Transit Relay server for Magic-Wormhole
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=		27

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.5.0:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
