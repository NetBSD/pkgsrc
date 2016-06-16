# $NetBSD: Makefile,v 1.4 2016/06/16 04:06:15 markd Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-11.89
TEXLIVE_REV=	38865

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extract bits of a LaTeX source for output
LICENSE=	gnu-gpl-v3

CONFLICTS=	teTeX-texmf<3.0nb32
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
