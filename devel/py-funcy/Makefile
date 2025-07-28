# $NetBSD: Makefile,v 1.2 2025/07/28 13:00:01 wiz Exp $

DISTNAME=	funcy-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/funcy/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/Suor/funcy
COMMENT=	Collection of fancy functional tools focused on practicality
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
#TEST_DEPENDS+=	${PYPKGPREFIX}-whatever>=0.7:../../devel/py-whatever

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
