# $NetBSD: Makefile,v 1.3 2016/01/27 10:53:20 markd Exp $

DISTNAME=	elsarticle
PKGNAME=	tex-${DISTNAME}-1.20
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Class for articles for submission to Elsevier journals
LICENSE=	lppl-1.2

DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-times-[0-9]*:../../fonts/tex-times
DEPENDS+=	tex-txfonts-[0-9]*:../../fonts/tex-txfonts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
