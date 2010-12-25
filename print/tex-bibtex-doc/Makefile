# $NetBSD: Makefile,v 1.5 2010/12/25 05:36:07 minskim Exp $

DISTNAME=	bibtex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.99d
TEXLIVE_REV=	20729

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-bibtex

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
