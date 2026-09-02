# $NetBSD: Makefile,v 1.4 2026/09/02 19:53:08 adam Exp $

DISTNAME=	funcy-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/funcy/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/Suor/funcy
COMMENT=	Collection of fancy functional tools focused on practicality
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-more-itertools>=4.0.0:../../devel/py-more-itertools
TEST_DEPENDS+=	${PYPKGPREFIX}-whatever>=0.7:../../devel/py-whatever

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
