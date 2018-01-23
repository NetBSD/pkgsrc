# $NetBSD: Makefile,v 1.8 2018/01/23 09:33:27 fhajny Exp $

DISTNAME=	boto3-1.5.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boto3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/boto3/
COMMENT=	Amazon Web Services SDK for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.8.34<1.9.0:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.7.1<1.0.0:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.1.10<0.2.0:../../net/py-s3transfer

USE_LANGUAGES=	# none

post-extract:
	${CHMOD} -R g-w,o-w ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
