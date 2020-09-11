# $NetBSD: Makefile,v 1.3 2020/09/11 02:06:38 js Exp $

GITHUB_PROJECT=	mautrix-python
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-mautrix-0.7.1
PKGREVISION=	1
EGG_NAME=	mautrix-${PKGVERSION_NOREV}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tulir/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/tulir/mautrix-python
COMMENT=	Python 3 asyncio Matrix framework
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3<4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-attrs>=18.1.0:../../devel/py-attrs

WRKSRC=		${WRKDIR}/mautrix-python-0.7.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
