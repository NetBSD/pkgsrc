# $NetBSD: Makefile,v 1.2 2016/01/30 03:26:09 markd Exp $

DISTNAME=	booktabs
PKGNAME=	tex-${DISTNAME}-1.61803
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Publication quality tables in LaTeX
LICENSE=	gnu-gpl-v2

CONFLICTS=	teTeX-texmf<3.0nb33
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
