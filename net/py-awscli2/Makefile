# $NetBSD: Makefile,v 1.1 2025/09/07 18:36:19 maya Exp $

DISTNAME=	awscli2-2.28.25
GITHUB_PROJECT=	aws-cli
GITHUB_TAG=	${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=aws/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aws.amazon.com/cli/
COMMENT=	Universal Command Line Interface for Amazon Web Services
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-botocore>=1.37.34:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-rsa>=3.1.2:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.11.0:../../net/py-s3transfer
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-awscrt-0.27.6{,nb*}:../../devel/py-awscrt
DEPENDS+=	${PYPKGPREFIX}-ruamel-base-[0-9]*:../../devel/py-ruamel-base
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-[0-9]*:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit-[0-9]*:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-distro-[0-9]*:../../devel/py-distro

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
