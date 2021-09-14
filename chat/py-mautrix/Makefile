# $NetBSD: Makefile,v 1.12 2021/09/14 19:19:35 js Exp $

DISTNAME=	mautrix-python-0.10.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-python//}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tulir/}
GITHUB_PROJECT=	mautrix-python
GITHUB_TAG=	v${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/python-${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/tulir/mautrix-python
COMMENT=	Python 3 asyncio Matrix framework
LICENSE=	mpl-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3<4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-attrs>=18.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-yarl>=1.5.1:../../www/py-yarl

USE_LANGUAGES=	# none
EGG_NAME=	mautrix-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
