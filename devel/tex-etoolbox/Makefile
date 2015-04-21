# $NetBSD: Makefile,v 1.2 2015/04/21 23:07:32 markd Exp $

DISTNAME=	etoolbox
PKGNAME=	tex-${DISTNAME}-2.1d
TEXLIVE_REV=	36574

MAINTAINER=	minskim@NetBSD.org
COMMENT=	e-TeX tools for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
