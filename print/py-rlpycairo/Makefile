# $NetBSD: Makefile,v 1.1 2025/12/28 14:20:03 adam Exp $

DISTNAME=	rlpycairo-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rlpycairo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.reportlab.com/
COMMENT=	Plugin backend renderer for reportlab.graphics.renderPM
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cairo>=1.20.0:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-freetype-py>=2.3:../../graphics/py-freetype-py

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
