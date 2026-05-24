# $NetBSD: Makefile,v 1.5 2026/05/24 05:59:28 adam Exp $

DISTNAME=	pickleshare-0.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pickleshare/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pickleshare/pickleshare
COMMENT=	Tiny shelve-like database with concurrency support
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
