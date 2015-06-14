# $NetBSD: Makefile,v 1.3 2015/06/14 10:16:08 markd Exp $

DISTNAME=	etoolbox
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	37189

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etoolbox
COMMENT=	e-TeX tools for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
