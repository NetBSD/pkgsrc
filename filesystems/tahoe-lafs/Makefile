# $NetBSD: Makefile,v 1.47 2021/03/18 23:23:31 gdt Exp $

DISTNAME=	tahoe-lafs-1.15.0
CATEGORIES=	filesystems
MASTER_SITES=	https://tahoe-lafs.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tahoe-lafs.org/
COMMENT=	Distributed fault-tolerant least-authority filesystem
LICENSE=	gnu-gpl-v2

USE_TOOLS=	gmake

BROKEN=		bulk builds are not happy and this is not important

# \todo: fix nevow doc location

PYTHON_VERSIONS_ACCEPTED=	27 # py-xml via py-nevow, py-zbase32, py-cryptopp
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

# from tahoe's setup.py
DEPENDS+=	${PYPKGPREFIX}-zfec>=1.1.0:../../converters/py-zfec
# \todo zope.interface
DEPENDS+=	${PYPKGPREFIX}-foolscap>=0.12.6:../../net/py-foolscap
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-twisted>=16.1.0:../../net/py-twisted
# bcrypt and appdirs required as twisted deps at runtime
DEPENDS+=	${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-nevow>=0.11.1:../../www/py-nevow
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-magic-wormhole-[0-9]*:../../net/py-magic-wormhole
DEPENDS+=	${PYPKGPREFIX}-eliot-[0-9]*:../../sysutils/py-eliot17
DEPENDS+=	${PYPKGPREFIX}-pyrsistent-[0-9]*:../../devel/py-pyrsistent
# \todo pyrsistent
# \todo attrs
# autobahn D2019.09.20.04.00.00
DEPENDS+=	${PYPKGPREFIX}-autobahn-[0-9]*:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-pyutil-[0-9]*:../../devel/py-pyutil
DEPENDS+=	${PYPKGPREFIX}-distro-[0-9]*:../../devel/py-distro

# 19.0.0 from 2020-01-01 works with 27
# \todo import/version an older one
DEPENDS+=       ${PYPKGPREFIX}-txtorcon-[0-9]*:../../net/py-txtorcon

# todo txi2p

# Not in setup.py, but seems to exist elsewhere.
#DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.8:../../security/py-asn1
#DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.0.5:../../security/py-asn1-modules
#DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.14:../../security/py-OpenSSL
#DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity

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
#	cd ${WRKSRC} && py.test-2.7

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
