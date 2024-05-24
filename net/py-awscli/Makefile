# $NetBSD: Makefile,v 1.66 2024/05/24 08:44:50 adam Exp $

DISTNAME=	awscli-1.32.112
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/awscli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-cli
COMMENT=	Universal Command Line Interface for Amazon Web Services
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-botocore>=1.34.83:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-rsa>=3.1.2:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.10.0:../../net/py-s3transfer
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
