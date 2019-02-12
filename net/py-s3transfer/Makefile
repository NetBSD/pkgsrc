# $NetBSD: Makefile,v 1.5 2019/02/12 10:54:52 adam Exp $

DISTNAME=	s3transfer-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/s3transfer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/s3transfer
COMMENT=	Amazon S3 Transfer Manager
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.12.36:../../net/py-botocore

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-futures>=2.2.0:../../devel/py-futures
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
