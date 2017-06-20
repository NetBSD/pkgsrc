# $NetBSD: Makefile,v 1.10 2017/06/20 20:56:52 markd Exp $

DISTNAME=	amsmath
PKGNAME=	tex-${DISTNAME}-2.16a
TEXLIVE_REV=	43813

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-amsmath
COMMENT=	AMS mathematical facilities for LaTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
