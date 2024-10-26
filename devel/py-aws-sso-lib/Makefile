# $NetBSD: Makefile,v 1.1 2024/10/26 02:56:24 schmonz Exp $

DISTNAME=	aws_sso_lib-1.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aws_sso_lib/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/benkehoe/aws-sso-util/blob/master/lib/README.md
COMMENT=	Library to make AWS SSO easier
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aws-error-utils>=2.4:../../devel/py-aws-error-utils
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.24.60:../../net/py-boto3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
