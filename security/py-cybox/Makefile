# $NetBSD: Makefile,v 1.6 2017/10/10 07:30:58 adam Exp $

DISTNAME=	python-cybox-2.1.0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
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
EGG_NAME=	${DISTNAME:S/^python-//}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
