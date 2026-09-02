# $NetBSD: Makefile,v 1.10 2026/09/02 15:11:01 adam Exp $

DISTNAME=	colorlog-6.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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
