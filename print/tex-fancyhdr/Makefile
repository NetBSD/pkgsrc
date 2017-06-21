# $NetBSD: Makefile,v 1.6 2017/06/21 06:13:15 markd Exp $

DISTNAME=	fancyhdr
PKGNAME=	tex-${DISTNAME}-3.9
TEXLIVE_REV=	44479

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fancyhdr
COMMENT=	Extensive control of page headers and footers in LaTeX2e
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
