# $NetBSD: Makefile,v 1.4 2010/12/25 05:36:07 minskim Exp $

DISTNAME=	bibtex
PKGNAME=	tex-${DISTNAME}-0.99d
TEXLIVE_REV=	20729

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Reference management software for LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
