# $NetBSD: Makefile,v 1.19 2018/01/23 09:30:53 fhajny Exp $

DISTNAME=	botocore-1.8.34
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

post-extract:
	${CHMOD} -R g-w,o-w ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
