# $NetBSD: Makefile,v 1.24 2018/08/21 14:42:40 adam Exp $

DISTNAME=	awscli-1.15.82
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/awscli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-cli
COMMENT=	Universal Command Line Interface for Amazon Web Services
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.10.81:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-rsa>=3.4.1:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.1.12:../../net/py-s3transfer
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
