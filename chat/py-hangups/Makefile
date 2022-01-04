# $NetBSD: Makefile,v 1.12 2022/01/04 20:52:37 wiz Exp $

DISTNAME=	hangups-0.4.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hangups/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tdryer/hangups
COMMENT=	Third-party instant messaging client for Google Hangouts
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-MechanicalSoup>=0.6.0:../../www/py-MechanicalSoup
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.7:../../www/py-aiohttp
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
