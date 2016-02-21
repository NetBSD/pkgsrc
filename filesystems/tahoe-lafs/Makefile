# $NetBSD: Makefile,v 1.31 2016/02/21 22:21:37 wiz Exp $

VERSION=	1.10.2
DISTNAME=	allmydata-tahoe-${VERSION}
PKGNAME=	tahoe-lafs-${VERSION}
CATEGORIES=	filesystems
MASTER_SITES=	https://tahoe-lafs.org/source/tahoe-lafs/releases/
#for beta, add
#MASTER_SITES+=		http://tahoe-lafs.org/source/tahoe-lafs/tarballs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
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

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-zfec-[0-9]*:../../converters/py-zfec
DEPENDS+=	${PYPKGPREFIX}-zbase32-[0-9]*:../../converters/py-zbase32
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-pyutil-[0-9]*:../../devel/py-pyutil
# Included egg setuptools_trial, not used.
# Included egg setuptools_darcs, used (no package yet).
DEPENDS+=	${PYPKGPREFIX}-foolscap>=0.8.0:../../net/py-foolscap
DEPENDS+=	${PYPKGPREFIX}-twisted>=13.0.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.8:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.0.5:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-characteristic>=14.0.0:../../devel/py-characteristic
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-cryptopp>=0.6.0:../../security/py-cryptopp
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-nevow>=0.11.1:../../www/py-nevow
DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-twisted, py-xml via py-nevow, py-zbase32, py-cryptopp
PYTHON_VERSIONS_INCOMPATIBLE+=  33 # not supported by py-service_identity>=16.0.0

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
REPLACE_PYTHON+= src/buildtest/test_build_with_fake_dist.py

PKG_GROUPS=	tahoes
PKG_USERS=	tahoes:tahoes
PKG_GECOS.tahoes=	tahoe server

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
