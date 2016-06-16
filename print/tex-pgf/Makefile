# $NetBSD: Makefile,v 1.15 2016/06/16 04:06:14 markd Exp $

DISTNAME=	pgf
PKGNAME=	tex-${DISTNAME}-3.0.1a
CATEGORIES=	print graphics
TEXLIVE_REV=	40966

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PostScript and PDF graphics systems for TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
