# $NetBSD: Makefile,v 1.3 2025/07/07 05:58:05 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-awscli-plugin-logs-tail-0.2
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=Corymbia/}
GITHUB_PROJECT=	logs-tail-awscli-plugin
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://pypi.org/project/awscli-plugin-logs-tail/
COMMENT=	CloudWatch Logs tail command plugin for AWS CLI
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-awscli>=1.14.0:../../net/py-awscli
DEPENDS+=	${PYPKGPREFIX}-botocore>=1.8.35:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.4:../../time/py-dateutil

WRKSRC=		${WRKDIR}/${DISTNAME}

WHEEL_NAME=	${PKGNAME_NOREV:C/^${PYPKGPREFIX}-//:S/-/_/g:S/_${PKGVERSION_NOREV}/-${PKGVERSION_NOREV}/}

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
