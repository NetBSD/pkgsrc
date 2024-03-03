# $NetBSD: Makefile,v 1.11 2024/03/03 18:12:22 leot Exp $

DISTNAME=	moderncv
PKGNAME=	tex-${DISTNAME}-2.3.1
PKGREVISION=	1
TEXLIVE_REV=	62128

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/moderncv
COMMENT=	Modern curriculum vitae class
LICENSE=	lppl-1.3c

DEPENDS+=	tex-arydshln-[0-9]*:../../print/tex-arydshln
DEPENDS+=	tex-changepage-[0-9]*:../../print/tex-changepage
DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
DEPENDS+=	tex-etoolbox>=2.1:../../devel/tex-etoolbox
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-fontawesome-[0-9]*:../../fonts/tex-fontawesome
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-marvosym-[0-9]*:../../fonts/tex-marvosym 
DEPENDS+=	tex-microtype-[0-9]*:../../print/tex-microtype
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xifthen-[0-9]*:../../devel/tex-xifthen

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
