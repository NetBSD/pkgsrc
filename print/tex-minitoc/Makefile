# $NetBSD: Makefile,v 1.1.1.1 2011/01/22 22:23:57 minskim Exp $

DISTNAME=	minitoc
PKGNAME=	tex-${DISTNAME}-60
TEXLIVE_REV=	16836

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Produce a table of contents for each chapter, part or section

CONFLICTS+=	teTeX-texmf<3.0nb29
DEPENDS+=	tex-cmsd>=2010:../../fonts/tex-cmsd
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-notoccite>=2009:../../print/tex-notoccite
DEPENDS+=	tex-placeins>=2.2:../../print/tex-placeins

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
