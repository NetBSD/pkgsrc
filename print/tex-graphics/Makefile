# $NetBSD: Makefile,v 1.24 2026/03/29 10:45:56 markd Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78282

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-graphics
COMMENT=	The LaTeX standard graphics bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg
DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
