# $NetBSD: Makefile,v 1.11 2026/09/08 09:52:16 adam Exp $

DISTNAME=	toolz-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toolz/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pytoolz/toolz
COMMENT=	List processing tools and functional utilities
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-git-versioning>=2.0:../../devel/py-setuptools-git-versioning

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
