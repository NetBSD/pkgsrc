# $NetBSD: Makefile,v 1.3 2026/09/02 19:54:22 adam Exp $

DISTNAME=	whatever-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/whatever/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/Suor/whatever
COMMENT=	Whatever Object - easy way to make lambdas
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
