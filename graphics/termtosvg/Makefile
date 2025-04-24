# $NetBSD: Makefile,v 1.8 2025/04/24 15:14:57 adam Exp $

DISTNAME=	termtosvg-1.1.0
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nbedos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nbedos.github.io/termtosvg/
COMMENT=	Record terminal sessions as SVG animations
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pyte-[0-9]*:../../devel/py-pyte
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
