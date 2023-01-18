# $NetBSD: Makefile,v 1.44 2023/01/18 09:08:39 adam Exp $

DISTNAME=	boto3-1.26.51
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boto3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/boto3
COMMENT=	Amazon Web Services SDK for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.29.51:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.7.1:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.6.0:../../net/py-s3transfer

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
