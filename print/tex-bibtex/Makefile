# $NetBSD: Makefile,v 1.11 2026/04/03 05:43:12 markd Exp $

DISTNAME=	bibtex
PKGNAME=	tex-${DISTNAME}-0.99e
TEXLIVE_REV=	77830

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bibtex
COMMENT=	Process bibliographies (bib files) for LaTeX or other formats
#LICENSE=	knuth

DEPENDS+=	web2c>=2013:../../print/web2c
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
