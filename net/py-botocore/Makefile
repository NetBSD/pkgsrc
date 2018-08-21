# $NetBSD: Makefile,v 1.24 2018/08/21 14:26:58 adam Exp $

DISTNAME=	botocore-1.10.81
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/botocore/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/botocore
COMMENT=	Low-level interface to a growing number of Amazon Web Services
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.5.3<3:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.7.1<1:../../textproc/py-jmespath

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
