# $NetBSD: Makefile,v 1.1 2023/06/17 12:03:06 markd Exp $

DISTNAME=	ptlatexcommands
PKGNAME=	tex-${DISTNAME}-0.1
TEXLIVE_REV=	67125

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ptlatexcommands
COMMENT=	LaTeX to commands in Portuguese
LICENSE=	mit

DEPENDS+=	tex-algorithms-[0-9]*:../../print/tex-algorithms
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-biblatex-[0-9]*:../../print/tex-biblatex
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
