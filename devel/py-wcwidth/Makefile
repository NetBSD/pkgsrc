# $NetBSD: Makefile,v 1.19 2024/11/11 07:28:30 wiz Exp $

DISTNAME=	wcwidth-0.2.13
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wcwidth/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jquast/wcwidth
COMMENT=	Measures number of Terminal column cells of wide-character codes
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
