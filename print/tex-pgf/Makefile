# $NetBSD: Makefile,v 1.12 2013/10/15 09:24:22 minskim Exp $

DISTNAME=	pgf
PKGNAME=	tex-${DISTNAME}-2.10
PKGREVISION=	1
CATEGORIES=	print graphics
TEXLIVE_REV=	20236

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PostScript and PDF graphics systems for TeX

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
