# $NetBSD: Makefile,v 1.39 2022/07/03 12:49:52 wiz Exp $

DISTNAME=	borgbackup-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/borgbackup/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/borgbackup/borg
COMMENT=	Deduplicating backup program with compression and encryption
LICENSE=	modified-bsd
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.1<1.0.5:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

PYTHON_VERSIONS_INCOMPATIBLE=	27 37
PYTHON_SELF_CONFLICT=		yes

USE_PKG_RESOURCES=	yes

MAKE_ENV+=	BORG_OPENSSL_PREFIX=${SSLBASE:Q}
MAKE_ENV+=	BORG_LZ4_PREFIX=${BUILDLINK_PREFIX.lz4}
MAKE_ENV+=	BORG_LIBZSTD_PREFIX=${BUILDLINK_PREFIX.zstd}
MAKE_ENV+=	BORG_LIBB2_PREFIX=${BUILDLINK_PREFIX.libb2}

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/*1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../security/libb2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
