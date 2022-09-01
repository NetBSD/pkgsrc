# $NetBSD: Makefile,v 1.21 2022/09/01 04:02:28 markd Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.4e
TEXLIVE_REV=	63514

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-graphics
COMMENT=	The LaTeX standard graphics bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
