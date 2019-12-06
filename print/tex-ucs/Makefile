# $NetBSD: Makefile,v 1.14 2019/12/06 20:23:37 markd Exp $

DISTNAME=	ucs
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	35853

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended UTF-8 input encoding for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
