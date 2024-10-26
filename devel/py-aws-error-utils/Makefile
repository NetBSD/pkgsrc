# $NetBSD: Makefile,v 1.1 2024/10/26 02:50:29 schmonz Exp $

DISTNAME=	aws_error_utils-2.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aws_error_utils/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/benkehoe/aws-error-utils
COMMENT=	Error-handling functions for boto3/botocore
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-botocore-[0-9]*:../../net/py-botocore

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
