# $NetBSD: Makefile,v 1.7 2015/04/22 22:45:21 markd Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.0p
TEXLIVE_REV=	35577

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Standard LaTeX graphics

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-def-[0-9]*:../../print/tex-pdftex-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
