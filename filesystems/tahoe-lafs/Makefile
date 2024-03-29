# $NetBSD: Makefile,v 1.62 2023/11/07 22:38:01 wiz Exp $

VERSION_BASE=	1.18.0
VERSION_RC=
DISTNAME=	tahoe-lafs-${VERSION_BASE}${VERSION_RC}
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	https://tahoe-lafs.org/downloads/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://tahoe-lafs.org/
COMMENT=	Distributed fault-tolerant least-authority filesystem
LICENSE=	gnu-gpl-v2

USE_TOOLS=	gmake

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_PKG_RESOURCES=	yes

## Dependencies are from tahoe's setup.py, in order, and try to follow
## setup.py's version requirements.
# install_requires
# setuptools 28.8.0
DEPENDS+=	${PYPKGPREFIX}-zfec>=1.1.0:../../converters/py-zfec
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=3.6.0:../../devel/py-zope.interface
DEPENDS+=	${PYPKGPREFIX}-foolscap>=21.7.0:../../net/py-foolscap
# twisted needs tls, conch options.  pkgsrc has tls.
# TODO: conch??
DEPENDS+=	${PYPKGPREFIX}-twisted>=19.10.0:../../net/py-twisted
# bcrypt and appdirs are required as twisted deps at runtime
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
DEPENDS+=	${PYPKGPREFIX}-collections-extended-[0-9]*:../../devel/py-collections-extended

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

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

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
