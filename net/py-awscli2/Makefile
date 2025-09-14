# $NetBSD: Makefile,v 1.2 2025/09/14 16:54:42 wiz Exp $

DISTNAME=	awscli2-2.28.25
PKGREVISION=	1
GITHUB_PROJECT=	aws-cli
GITHUB_TAG=	${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=aws/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aws.amazon.com/cli/
COMMENT=	Universal Command Line Interface for Amazon Web Services
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=0:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-awscrt-0.27.6{,nb*}:../../devel/py-awscrt
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.2.5:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-distro>=1.5:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.7.1:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=3.0.24:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25.4:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-jsonschema>=0:../../textproc/py-jsonschema

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/awscli/botocore/httpsession.py.orig

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
# as of 2.28.25
# 371 failed, 125630 passed, 88 skipped, 1419 warnings, 375 errors
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
