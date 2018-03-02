# $NetBSD: Makefile,v 1.10 2018/03/02 14:58:01 adam Exp $

DISTNAME=	boto3-1.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boto3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/boto3/
COMMENT=	Amazon Web Services SDK for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.9.3:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.7.1:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.1.10:../../net/py-s3transfer

USE_LANGUAGES=	# none

post-extract:
	${CHMOD} -R g-w,o-w ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
