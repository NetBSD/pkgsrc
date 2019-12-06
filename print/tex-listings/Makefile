# $NetBSD: Makefile,v 1.10 2019/12/06 20:21:53 markd Exp $

DISTNAME=	listings
PKGNAME=	tex-${DISTNAME}-1.8b
TEXLIVE_REV=	50175

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/listings
COMMENT=	Typeset source code listings using LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-algorithms-[0-9]*:../../print/tex-algorithms
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-url>=3.2:../../print/tex-url

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
