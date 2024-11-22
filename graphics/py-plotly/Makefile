# $NetBSD: Makefile,v 1.2 2024/11/22 21:57:12 wiz Exp $

DISTNAME=	plotly-5.24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/plotly/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://plotly.com/python/
COMMENT=	Interactive graphing library for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-tenacity>=6.2.0:../../devel/py-tenacity

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
