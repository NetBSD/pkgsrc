# $NetBSD: Makefile,v 1.6 2022/07/05 10:16:50 adam Exp $

DISTNAME=	termtosvg-1.1.0
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nbedos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nbedos.github.io/termtosvg/
COMMENT=	Record terminal sessions as SVG animations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pyte-[0-9]*:../../devel/py-pyte
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-pyte

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
