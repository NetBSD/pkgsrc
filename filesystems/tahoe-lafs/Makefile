# $NetBSD: Makefile,v 1.2 2010/07/24 19:19:06 gdt Exp $
#

VERSION=	1.7.1
DISTNAME=	allmydata-tahoe-${VERSION}
PKGNAME=	tahoe-lafs-${VERSION}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	http://tahoe-lafs.org/source/tahoe-lafs/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://tahoe-lafs.org/
COMMENT=	Distributed fault-tolerant least-authority filesystem
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# TODO
# fix nevow: doc location

DEPENDS+=	${PYPKGPREFIX}-zfec:../../converters/py-zfec
DEPENDS+=	${PYPKGPREFIX}-zbase32:../../converters/py-zbase32
DEPENDS+=	${PYPKGPREFIX}-simplejson:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-argparse:../../devel/py-argparse
# Included egg darcsver, but depend anyway.
DEPENDS+=	${PYPKGPREFIX}-darcsver:../../devel/py-darcsver
DEPENDS+=	${PYPKGPREFIX}-pyutil:../../devel/py-pyutil
# Included egg setuptools_trial, not used.
# Included egg setuptools_darcs, used (no package yet).
DEPENDS+=	${PYPKGPREFIX}-foolscap:../../net/py-foolscap
DEPENDS+=	${PYPKGPREFIX}-twisted:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-asn1:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-crypto:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-cryptopp:../../security/py-cryptopp
DEPENDS+=	${PYPKGPREFIX}-OpenSSL:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-nevow:../../www/py-nevow

# Distfile has files mode 600, which leads to root-owned 600 files in
# the binary package.
post-extract:
	echo "Fixing distfile contents to be world readable:"
	chmod -R +r ${WRKSRC}

REPLACE_PYTHON+= src/allmydata/reliability.py
REPLACE_PYTHON+= src/allmydata/storage/shares.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
