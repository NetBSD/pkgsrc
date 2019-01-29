# $NetBSD: Makefile,v 1.16 2019/01/29 19:54:29 markd Exp $

DISTNAME=	pgf
PKGNAME=	tex-${DISTNAME}-3.1
CATEGORIES=	print graphics
TEXLIVE_REV=	49607

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
