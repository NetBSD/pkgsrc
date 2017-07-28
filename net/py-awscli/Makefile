# $NetBSD: Makefile,v 1.8 2017/07/28 07:09:46 adam Exp $

DISTNAME=	awscli-1.11.127
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/awscli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-cli/
COMMENT=	Universal Command Line Interface for Amazon Web Services
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.5.79:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-rsa>=3.4.1:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.1.9:../../net/py-s3transfer
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
