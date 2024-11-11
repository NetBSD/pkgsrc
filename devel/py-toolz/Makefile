# $NetBSD: Makefile,v 1.9 2024/11/11 07:28:28 wiz Exp $

DISTNAME=	toolz-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toolz/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pytoolz/toolz
COMMENT=	List processing tools and functional utilities
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
