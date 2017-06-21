# $NetBSD: Makefile,v 1.12 2017/06/21 07:24:06 markd Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.2a
TEXLIVE_REV=	44579

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-graphics
COMMENT=	Standard LaTeX graphics
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
