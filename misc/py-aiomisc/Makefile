# $NetBSD: Makefile,v 1.2 2026/10/26 16:08:18 adam Exp $

DISTNAME=	aiomisc-18.0.37
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiomisc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aiokitchen/aiomisc
COMMENT=	Miscellaneous utils for asyncio
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-aiothreads>=1.1.4:../../misc/py-aiothreads
DEPENDS+=	${PYPKGPREFIX}-colorlog>=6.0:../../devel/py-colorlog

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
