# $NetBSD: Makefile,v 1.33 2021/02/25 09:12:02 adam Exp $

DISTNAME=	boto3-1.17.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boto3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/boto3
COMMENT=	Amazon Web Services SDK for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.20.15:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.7.1:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.3.0:../../net/py-s3transfer

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
