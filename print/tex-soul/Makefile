# $NetBSD: Makefile,v 1.2 2016/01/26 11:15:18 markd Exp $

DISTNAME=	soul
PKGNAME=	tex-${DISTNAME}-2.4
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for letterspacing, underlining, and more
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
