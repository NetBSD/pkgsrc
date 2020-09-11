# $NetBSD: Makefile,v 1.3 2020/09/11 02:38:31 js Exp $

PKGNAME=	${PYPKGPREFIX}-tulir-hangups-0.4.12
PKGREVISION=	1
DISTNAME=	v${PKGVERSION_NOREV}
EGG_NAME=	tulir_hangups-${PKGVERSION_NOREV}
GITHUB_PROJECT=	hangups
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tulir/}
DIST_SUBDIR=	tulir-hangups

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/tulir/hangups
COMMENT=	Fork of py-hangups for use with mautrix-hangouts
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-MechanicalSoup>=0.6.0:../../www/py-MechanicalSoup
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.3:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.0:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=2:../../devel/py-async-timeout
DEPENDS+=	${PYPKGPREFIX}-configargparse>=0.11.0:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.1.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-readlike>=0.1.2:../../devel/py-readlike
DEPENDS+=	${PYPKGPREFIX}-reparser>=1.4.3:../../devel/py-reparser
DEPENDS+=	${PYPKGPREFIX}-requests>=2.6.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-urwid>=1.3.1:../../devel/py-urwid

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
