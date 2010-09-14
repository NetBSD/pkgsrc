# $NetBSD: Makefile,v 1.4 2010/09/14 00:18:11 minskim Exp $

DISTNAME=	fancyhdr
PKGNAME=	tex-${DISTNAME}-3.1
PKGREVISION=	1
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extensive control of page headers and footers in LaTeX2e

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
