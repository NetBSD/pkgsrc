# $NetBSD: Makefile,v 1.8 2016/06/16 04:05:59 markd Exp $

DISTNAME=	algorithm2e
PKGNAME=	tex-${DISTNAME}-5.1
TEXLIVE_REV=	38805

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Floating algorithm environment with algorithmic keywords
LICENSE=	lppl-1.3c

DEPENDS+=	tex-endfloat-[0-9]*:../../print/tex-endfloat
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-relsize-[0-9]*:../../print/tex-relsize
DEPENDS+=	tex-tocbibind-[0-9]*:../../print/tex-tocbibind
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
