# $NetBSD: Makefile,v 1.4 2016/01/27 10:13:21 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-2.5a
TEXLIVE_REV=	30755

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Interface to the micro-typographic features of pdfTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
