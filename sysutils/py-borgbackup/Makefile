# $NetBSD: Makefile,v 1.35 2022/01/05 15:41:21 wiz Exp $

DISTNAME=	borgbackup-1.1.17
PKGREVISION=	3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/borgbackup/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/borgbackup/borg
COMMENT=	Deduplicating backup program with compression and encryption
LICENSE=	modified-bsd
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

MAKE_ENV+=	BORG_OPENSSL_PREFIX=${SSLBASE:Q}
MAKE_ENV+=	BORG_LZ4_PREFIX=${BUILDLINK_PREFIX.lz4}
MAKE_ENV+=	BORG_LIBZSTD_PREFIX=${BUILDLINK_PREFIX.zstd}
MAKE_ENV+=	BORG_LIBB2_PREFIX=${BUILDLINK_PREFIX.libb2}


post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} borg borg-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} borgfs borgfs-${PYVERSSUFFIX} || ${TRUE}

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../security/libb2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
