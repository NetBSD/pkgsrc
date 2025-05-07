# $NetBSD: Makefile,v 1.23 2025/05/07 20:23:19 markd Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.4g
TEXLIVE_REV=	72739

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-graphics
COMMENT=	The LaTeX standard graphics bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
