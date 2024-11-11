# $NetBSD: Makefile,v 1.7 2024/11/11 07:28:04 wiz Exp $

DISTNAME=	colorlog-6.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/colorlog/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/borntyping/python-colorlog
COMMENT=	Log formatting with colors
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
