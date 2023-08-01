# $NetBSD: Makefile,v 1.20 2023/08/01 23:20:38 wiz Exp $

DISTNAME=	python-0.16.3
PKGNAME=	${PYPKGPREFIX}-mautrix-${DISTNAME:S/python-//}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mautrix/}
GITHUB_PROJECT=	python
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/tulir/mautrix-python
COMMENT=	Python 3 asyncio Matrix framework
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3<4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-attrs>=18.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-yarl>=1.5.1:../../www/py-yarl

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none
EGG_NAME=	mautrix-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
