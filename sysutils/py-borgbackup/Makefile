# $NetBSD: Makefile,v 1.12 2017/08/05 10:25:46 bsiegert Exp $

DISTNAME=	borgbackup-1.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=b/borgbackup/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/borgbackup/borg
COMMENT=	Deduplicating backup program with compression and encryption
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.4.6:../../devel/py-msgpack

PYTHON_VERSIONS_INCOMPATIBLE=	27

MAKE_ENV+=	BORG_OPENSSL_PREFIX=${SSLBASE:Q}
MAKE_ENV+=	BORG_LZ4_PREFIX=${BUILDLINK_PREFIX.lz4}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} borg borg-${PYVERSSUFFIX} || ${TRUE}

.include "../../archivers/lz4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
