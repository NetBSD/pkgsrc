# $NetBSD: Makefile,v 1.1.1.1 2011/10/27 23:22:11 minskim Exp $

DISTNAME=	etoolbox
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	20922

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Tool-box for LaTeX programmers using e-TeX

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
