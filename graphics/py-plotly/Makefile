# $NetBSD: Makefile,v 1.3 2025/04/15 15:17:48 adam Exp $

DISTNAME=	plotly-5.24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/plotly/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://plotly.com/python/
COMMENT=	Interactive graphing library for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-tenacity>=6.2.0:../../devel/py-tenacity

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
