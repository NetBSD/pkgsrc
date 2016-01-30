# $NetBSD: Makefile,v 1.2 2016/01/30 03:26:08 markd Exp $

DISTNAME=	bibtopic
PKGNAME=	tex-${DISTNAME}-1.1a
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Include multiple bibliographies in a document
LICENSE=	gnu-gpl-v2

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
