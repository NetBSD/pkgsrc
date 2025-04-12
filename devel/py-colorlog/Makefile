# $NetBSD: Makefile,v 1.8 2025/04/12 09:50:46 adam Exp $

DISTNAME=	colorlog-6.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/colorlog/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/borntyping/python-colorlog
COMMENT=	Log formatting with colors
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
