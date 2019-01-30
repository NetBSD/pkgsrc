# $NetBSD: Makefile,v 1.4 2019/01/30 09:38:18 markd Exp $

DISTNAME=	elsarticle
PKGNAME=	tex-${DISTNAME}-3.1
TEXLIVE_REV=	49714

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/elsarticle
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
