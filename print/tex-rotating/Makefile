# $NetBSD: Makefile,v 1.4 2016/01/27 09:27:48 markd Exp $

DISTNAME=	rotating
PKGNAME=	tex-${DISTNAME}-2.16b
TEXLIVE_REV=	16832

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Rotation tools including rotated full-page floats
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
