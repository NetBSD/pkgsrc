# $NetBSD: Makefile,v 1.4 2016/06/16 03:54:43 markd Exp $

DISTNAME=	etoolbox
PKGNAME=	tex-${DISTNAME}-2.2a
TEXLIVE_REV=	38031

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etoolbox
COMMENT=	e-TeX tools for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
