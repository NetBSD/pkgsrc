# $NetBSD: Makefile,v 1.9 2018/06/24 11:17:04 adam Exp $

DISTNAME=	stix-1.2.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
#MASTER_SITES=	${MASTER_SITE_PYPI:=s/stix/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=STIXProject/}
GITHUB_PROJECT=	python-stix
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://stixproject.github.io/
COMMENT=	Python library for manipulating STIX content
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cybox>=2.1.0.14:../../security/py-cybox
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-mixbox>=1.0.2:../../devel/py-mixbox

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
