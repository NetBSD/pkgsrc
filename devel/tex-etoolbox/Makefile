# $NetBSD: Makefile,v 1.10 2020/04/27 03:26:38 markd Exp $

DISTNAME=	etoolbox
PKGNAME=	tex-${DISTNAME}-2.5h
TEXLIVE_REV=	52153

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/etoolbox
COMMENT=	e-TeX tools for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
