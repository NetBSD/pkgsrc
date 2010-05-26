# $NetBSD: Makefile,v 1.2 2010/05/26 04:43:42 minskim Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-2.4
TEXLIVE_REV=	16687

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Interface to the micro-typographic features of pdfTeX

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
