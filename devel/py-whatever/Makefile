# $NetBSD: Makefile,v 1.2 2025/07/28 16:24:39 wiz Exp $

DISTNAME=	whatever-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/whatever/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/Suor/whatever
COMMENT=	Whatever Object - easy way to make lambdas
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
