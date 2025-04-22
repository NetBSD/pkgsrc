# $NetBSD: Makefile,v 1.9 2025/04/22 19:54:59 wiz Exp $

DISTNAME=	appdirs-1.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/appdirs/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ActiveState/appdirs
COMMENT=	Module for determining appropriate, platform-specific dirs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
