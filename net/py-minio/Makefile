# $NetBSD: Makefile,v 1.17 2023/11/16 09:20:27 adam Exp $

DISTNAME=	minio-7.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/minio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/minio/minio-py
COMMENT=	MinIO Python SDK for Amazon S3 Compatible Cloud Storage
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-argon2-cffi-[0-9]*:../../security/py-argon2-cffi
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
