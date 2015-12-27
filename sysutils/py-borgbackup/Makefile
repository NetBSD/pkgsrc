# $NetBSD: Makefile,v 1.1 2015/12/27 21:06:06 wiz Exp $

DISTNAME=	borgbackup-0.29.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=b/borgbackup/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/borgbackup/borg
COMMENT=	Deduplicating backup program with compression and encryption
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.4.6:../../devel/py-msgpack

PYTHON_VERSIONS_INCOMPATIBLE=	27

MAKE_ENV+=	BORG_OPENSSL_PREFIX=${SSLBASE:Q}
MAKE_ENV+=	BORG_LZ4_PREFIX=${BUILDLINK_PREFIX.lz4}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv borg borg-${PYVERSSUFFIX}

.include "../../archivers/lz4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
