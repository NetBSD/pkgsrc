# $NetBSD: Makefile,v 1.22 2014/05/09 07:37:05 wiz Exp $

VERSION=	1.10.0
PKGREVISION=	2
DISTNAME=	allmydata-tahoe-${VERSION}
EGG_NAME=	allmydata_tahoe-${VERSION}
PKGNAME=	tahoe-lafs-${VERSION}
CATEGORIES=	filesystems
MASTER_SITES=	https://tahoe-lafs.org/source/tahoe-lafs/releases/
#for beta, add
#MASTER_SITES+=		http://tahoe-lafs.org/source/tahoe-lafs/tarballs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://tahoe-lafs.org/
COMMENT=	Distributed fault-tolerant least-authority filesystem
LICENSE=	gnu-gpl-v2

USE_TOOLS=	gmake

# $WRKDIR/Makefile has 'python' hardcoded; this works after hand-patching
TEST_TARGET=	test

# TODO
# fix nevow: doc location

# Included egg darcsver, but depend anyway.
BUILD_DEPENDS+=	${PYPKGPREFIX}-darcsver-[0-9]*:../../devel/py-darcsver

DEPENDS+=	${PYPKGPREFIX}-zfec-[0-9]*:../../converters/py-zfec
DEPENDS+=	${PYPKGPREFIX}-zbase32-[0-9]*:../../converters/py-zbase32
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-pyutil-[0-9]*:../../devel/py-pyutil
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
# Included egg setuptools_trial, not used.
# Included egg setuptools_darcs, used (no package yet).
DEPENDS+=	${PYPKGPREFIX}-foolscap>=0.6.3:../../net/py-foolscap
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-cryptopp-[0-9]*:../../security/py-cryptopp
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-nevow-[0-9]*:../../www/py-nevow

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-twisted, py-xml via py-nevow, py-zbase32, py-cryptopp

# Note that there is an upstream (inherited from setuptools) bug
#   https://tahoe-lafs.org/trac/tahoe-lafs/ticket/1258#comment:29 that
# will cause a build to fail if there is a package with bad modes
# installed.  If you get mysterious failures, pkg_delete the installed
# version.

# OK: 1.9.1, 1.9.2, 1.10a2
# BAD: 1.10a1
#BAD_DISTFILE_MODES=yes
.if defined(BAD_DISTFILE_MODES)
# Distfile has files mode 600, which leads to root-owned 600 files in
# the binary package.
post-extract:
	${ECHO} "Fixing distfile contents to be world readable:"
	chmod -R +r ${WRKSRC}
.endif

REPLACE_PYTHON+= src/allmydata/reliability.py
REPLACE_PYTHON+= src/allmydata/storage/shares.py

PKG_GROUPS=	tahoes
PKG_USERS=	tahoes:tahoes
PKG_GECOS.tahoes=	tahoe server

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
