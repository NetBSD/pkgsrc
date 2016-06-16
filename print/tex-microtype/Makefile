# $NetBSD: Makefile,v 1.5 2016/06/16 04:06:12 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-2.6a
TEXLIVE_REV=	41127

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Interface to the micro-typographic features of pdfTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
