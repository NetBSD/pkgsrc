# $NetBSD: Makefile,v 1.7 2017/11/30 08:16:19 adam Exp $

DISTNAME=	cybox-2.1.0.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=CybOXProject/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/CybOXProject/python-cybox
COMMENT=	Python library for manipulating CybOX content
LICENSE=	modified-bsd

GITHUB_PROJECT=	python-cybox
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-mixbox>=1.0.2:../../devel/py-mixbox

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
