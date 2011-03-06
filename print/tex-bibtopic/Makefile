# $NetBSD: Makefile,v 1.1.1.1 2011/03/06 21:48:54 minskim Exp $

DISTNAME=	bibtopic
PKGNAME=	tex-${DISTNAME}-1.1a
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Include multiple bibliographies in a document

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
