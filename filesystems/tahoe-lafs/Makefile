# $NetBSD: Makefile,v 1.53 2022/01/04 20:53:51 wiz Exp $

VERSION_BASE=	1.16.0
VERSION_RC=
DISTNAME=	tahoe-lafs-${VERSION_BASE}${VERSION_RC}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	https://tahoe-lafs.org/downloads/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://tahoe-lafs.org/
COMMENT=	Distributed fault-tolerant least-authority filesystem
LICENSE=	gnu-gpl-v2

USE_TOOLS=	gmake

# tahoe works with 27, but we depend on things which are
# not available for 27 in pkgsrc.
PYTHON_VERSIONS_INCOMPATIBLE=	27

# The world sees this as part of base python.
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

## Dependencies are from tahoe's setup.py, in order
# install_requires
# setuptools 28.8.0
DEPENDS+=	${PYPKGPREFIX}-zfec>=1.1.0:../../converters/py-zfec
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.6.0:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-foolscap>=21.7.0:../../net/py-foolscap
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.6:../../security/py-cryptography
# twisted needs tls, conch options.  pkgsrc has tls.
# TODO: conch??
DEPENDS+=	${PYPKGPREFIX}-twisted>=19.10.0:../../net/py-twisted
# bcrypt and appdirs required as twisted deps at runtime
# TODO: resolve
DEPENDS+=	${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-magic-wormhole>=0.10.2:../../net/py-magic-wormhole
DEPENDS+=	${PYPKGPREFIX}-eliot>=1.13.0:../../sysutils/py-eliot
DEPENDS+=	${PYPKGPREFIX}-pyrsistent-[0-9]*:../../devel/py-pyrsistent
DEPENDS+=	${PYPKGPREFIX}-attrs>=18.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-autobahn>=19.5.2:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-future>=0.18.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-netifaces-[0-9]*:../../net/py-netifaces
DEPENDS+=	${PYPKGPREFIX}-pyutil>=3.3.0:../../devel/py-pyutil
DEPENDS+=	${PYPKGPREFIX}-distro>=1.4.0:../../devel/py-distro
# tor_requires
DEPENDS+=	${PYPKGPREFIX}-txtorcon>=0.17.0:../../net/py-txtorcon
# txi2p-requires
# DEPENDS+=	${PYPKGPREFIX}-txi2p-tahoe>=0.3.5:../../net/py-txi2p-tahoe

# test_requires
# pyflakes
# coverage
# mock
# tox
# pytest
# pytest-twisted
# hypothesis
# treq
# towncrier
# testtools
# fixtures
# beautifulsoup4
# html5lib
# junitxml
# tenacity
# paramiko
# pytest-timeout

# Note that there is an upstream (inherited from setuptools) bug
#   https://tahoe-lafs.org/trac/tahoe-lafs/ticket/1258#comment:29 that
# will cause a build to fail if there is a package with bad modes
# installed.  If you get mysterious failures, pkg_delete the installed
# version.

PKG_GROUPS=		tahoes
PKG_USERS=		tahoes:tahoes
PKG_GECOS.tahoes=	tahoe server

# \todo Convert do-test to use tox
#do-test:
#	cd ${WRKSRC} && py.test-3.8

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
