# $NetBSD: Makefile,v 1.14 2022/01/04 20:54:45 wiz Exp $

DISTNAME=	stix-1.2.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stix/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://stixproject.github.io/
COMMENT=	Python library for manipulating STIX content
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cybox>=2.1.0.14:../../security/py-cybox
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-mixbox>=1.0.2:../../devel/py-mixbox

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-mixbox, py-cybox, py-ordered-set

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
