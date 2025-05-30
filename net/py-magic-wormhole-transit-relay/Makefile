# $NetBSD: Makefile,v 1.8 2025/05/30 12:59:39 gdt Exp $

DISTNAME=	magic-wormhole-transit-relay-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/magic-wormhole-transit-relay/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magic-wormhole/magic-wormhole-transit-relay
COMMENT=	Transit Relay server for Magic-Wormhole
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	39

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-twisted>=21.2.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-autobahn>=21.3.1:../../www/py-autobahn
TEST_DEPENDS+=	${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
