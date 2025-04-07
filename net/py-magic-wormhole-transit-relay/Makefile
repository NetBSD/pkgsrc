# $NetBSD: Makefile,v 1.6 2025/04/07 19:43:40 gdt Exp $

DISTNAME=	magic-wormhole-transit-relay-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/magic-wormhole-transit-relay/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magic-wormhole/magic-wormhole-transit-relay
COMMENT=	Transit Relay server for Magic-Wormhole
LICENSE=	mit

USE_LANGUAGES=	# none

# setup.py install_requires
DEPENDS+=	${PYPKGPREFIX}-twisted>=21.2.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-autobahn>=21.3.1:../../www/py-autobahn

# setup.py extras_requires dev
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes

# setup.py extras_requires release
#   dulwich
#   docutils
#   gpg
#TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
