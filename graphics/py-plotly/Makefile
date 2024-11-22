# $NetBSD: Makefile,v 1.1 2024/11/22 21:07:08 bacon Exp $

DISTNAME=	plotly-5.24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/plotly/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://plotly.com/python/
COMMENT=	Interactive graphing library for Python
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-tenacity>=6.2.0:../../devel/py-tenacity

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
