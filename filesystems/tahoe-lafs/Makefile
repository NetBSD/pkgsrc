# $NetBSD: Makefile,v 1.74 2025/05/30 13:02:44 gdt Exp $

VERSION_BASE=	1.20.0
VERSION_RC=
DISTNAME=	tahoe_lafs-${VERSION_BASE}${VERSION_RC}
PKGNAME=	tahoe-lafs-${VERSION_BASE}${VERSION_RC}
PKGREVISION=	3
CATEGORIES=	filesystems
MASTER_SITES=	https://tahoe-lafs.org/downloads/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://tahoe-lafs.org/trac/tahoe-lafs
COMMENT=	Distributed fault-tolerant least-authority filesystem
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}

PYTHON_VERSIONS_INCOMPATIBLE=	39

## pyproject.toml build:
# TOOL_DEPENDS+=	${PYPKGPREFIX}-dulwich>=0:../../devel/py-dulwich # not apparently used
# GnupG (unclear)
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs

## pyproject.toml dependencies:
DEPENDS+=			${PYPKGPREFIX}-zfec>=1.1.0:../../converters/py-zfec
DEPENDS+=			${PYPKGPREFIX}-zope.interface>=3.6.0:../../devel/py-zope.interface
DEPENDS+=			${PYPKGPREFIX}-foolscap>=23.3.0:../../net/py-foolscap
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography # >= 2.6
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL # >=23.2.0

# tahoe requires "Twisted[tls,conch]".  pkgsrc py-twisted appears to
# have both, but cautions that ssh client/server needs
# security/py-amkCrypto.
DEPENDS+=	${PYPKGPREFIX}-twisted>=22.8.0:../../net/py-twisted
# \todo DEPENDS+= security/py-amkCrypto

DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-magic-wormhole>=0.10.2:../../net/py-magic-wormhole
DEPENDS+=	${PYPKGPREFIX}-eliot>=1.14.0:../../sysutils/py-eliot
DEPENDS+=	${PYPKGPREFIX}-pyrsistent-[0-9]*:../../devel/py-pyrsistent
DEPENDS+=	${PYPKGPREFIX}-attrs>=20.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-autobahn>=22.4.3:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-future>=0.18.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-netifaces-[0-9]*:../../net/py-netifaces
DEPENDS+=	${PYPKGPREFIX}-pyutil>=3.3.0:../../devel/py-pyutil
DEPENDS+=	${PYPKGPREFIX}-distro>=1.4.0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-collections-extended>=2.0.2:../../devel/py-collections-extended
DEPENDS+=	${PYPKGPREFIX}-klein>=23.5.0:../../www/py-klein
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=2.2.0:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-treq-[0-9]*:../../devel/py-treq
DEPENDS+=	${PYPKGPREFIX}-cbor2>5.6.0:../../devel/py-cbor2
DEPENDS+=	${PYPKGPREFIX}-cddl>=0.6.1:../../devel/py-cddl
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock
# optional tor:
DEPENDS+=	${PYPKGPREFIX}-txtorcon>=0.17.0:../../net/py-txtorcon
# optional i2p:
# Needs a tahoe-specific fork because txi2p is unhealthy.  Therefore,
# omit i2p support.
# DEPENDS+=	${PYPKGPREFIX}-txi2p-tahoe>=0.3.5:../../net/py-txi2p-tahoe

# test:
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tox>=4.0.0:../../devel/py-tox
# py-test (included automatically via wheel.mk)
# pytest-twisted
# hypothesis >= 3.6.1
# towncrier
# testtools
# fixtures
# beautifulsoup4
# html5lib
# paramiko < 2.9
# pytest-timeout
# prometheus-client == 0.11.0

# Note that there is an upstream (inherited from setuptools) bug
#   https://tahoe-lafs.org/trac/tahoe-lafs/ticket/1258#comment:29 that
# will cause a build to fail if there is a package with bad modes
# installed.  If you get mysterious failures, pkg_delete the installed
# version.

PKG_GROUPS=		tahoes
PKG_USERS=		tahoes:tahoes
PKG_GECOS.tahoes=	tahoe server

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
