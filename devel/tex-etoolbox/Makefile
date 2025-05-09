# $NetBSD: Makefile,v 1.12 2025/05/09 23:58:25 markd Exp $

DISTNAME=	etoolbox
PKGNAME=	tex-${DISTNAME}-2.5l
TEXLIVE_REV=	73881

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/etoolbox
COMMENT=	e-TeX tools for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
