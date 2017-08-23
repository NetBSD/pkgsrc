# $NetBSD: Makefile,v 1.6 2017/08/23 22:37:59 markd Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-11.91
TEXLIVE_REV=	44883

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/preview
COMMENT=	Extract bits of a LaTeX source for output
LICENSE=	gnu-gpl-v3

CONFLICTS=	teTeX-texmf<3.0nb32
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
