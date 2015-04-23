# $NetBSD: Makefile,v 1.3 2015/04/23 12:22:10 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-2.5a
TEXLIVE_REV=	30755

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Interface to the micro-typographic features of pdfTeX

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
