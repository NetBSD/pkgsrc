# $NetBSD: Makefile,v 1.9 2020/05/13 21:48:05 adam Exp $

DISTNAME=	cybox-2.1.0.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cybox/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/CybOXProject/python-cybox
COMMENT=	Python library for manipulating CybOX content
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-mixbox>=1.0.2:../../devel/py-mixbox

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
