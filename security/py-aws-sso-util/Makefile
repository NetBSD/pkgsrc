# $NetBSD: Makefile,v 1.2 2024/10/26 19:08:41 schmonz Exp $

DISTNAME=	aws_sso_util-4.33.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aws_sso_util/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/benkehoe/aws-sso-util
COMMENT=	Smooth out the rough edges of AWS SSO
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-awscli-[0-9]*:../../net/py-awscli
DEPENDS+=	${PYPKGPREFIX}-aws-error-utils>=2.4:../../devel/py-aws-error-utils
DEPENDS+=	${PYPKGPREFIX}-aws-sso-lib>=1.13.0:../../devel/py-aws-sso-lib
DEPENDS+=	${PYPKGPREFIX}-botocore-[0-9]*:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.24.60:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.0.1:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-requests>=2.26.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.1:../../textproc/py-yaml

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} aws-sso-util aws-sso-util-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
