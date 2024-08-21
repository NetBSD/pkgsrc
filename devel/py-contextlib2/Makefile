# $NetBSD: Makefile,v 1.5 2024/08/21 08:06:46 adam Exp $

DISTNAME=	contextlib2-21.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/contextlib2/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://contextlib2.readthedocs.org/
COMMENT=	Backports and enhancements for the contextlib module
LICENSE=	python-software-foundation AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
