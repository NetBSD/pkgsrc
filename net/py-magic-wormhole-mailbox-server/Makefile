# $NetBSD: Makefile,v 1.9 2025/05/30 12:59:39 gdt Exp $

DISTNAME=	magic-wormhole-mailbox-server-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/magic-wormhole-mailbox-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magic-wormhole/magic-wormhole-mailbox-server
COMMENT=	Main server for Magic Wormhole
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	39

# setup.py install_requires
DEPENDS+=	${PYPKGPREFIX}-attrs>=16.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.5.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.14.1:../../www/py-autobahn
# Uses pkg_resources (which is deprecated).  wheel.mk lacks support
# for declaring this with a variable, because it's now rare.
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

# setup.py extras_requires dev
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-treq-[0-9]*:../../devel/py-treq
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
