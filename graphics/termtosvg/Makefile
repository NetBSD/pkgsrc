# $NetBSD: Makefile,v 1.4 2022/06/27 15:29:16 fcambus Exp $

DISTNAME=	termtosvg-1.1.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nbedos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nbedos.github.io/termtosvg/
COMMENT=	Record terminal sessions as SVG animations
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pyte-[0-9]*:../../devel/py-pyte
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
