# $NetBSD: Makefile,v 1.47 2021/04/15 05:01:52 adam Exp $

DISTNAME=	awscli-1.19.52
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/awscli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-cli
COMMENT=	Universal Command Line Interface for Amazon Web Services
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.20.52:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.3.0:../../net/py-s3transfer
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONED_DEPENDENCIES+=	rsa

post-extract:
	${FIND} ${WRKSRC}/awscli/examples -type f -exec ${CHMOD} -R a-x {} +

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
