# $NetBSD: Makefile,v 1.11 2026/06/24 08:27:40 adam Exp $

DISTNAME=	ipython_genutils-0.2.0
PKGREVISION=	4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython_genutils/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Vestigial utilities from IPython
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
