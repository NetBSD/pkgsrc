# $NetBSD: Makefile,v 1.6 2011/03/03 23:13:18 minskim Exp $

DISTNAME=	bibtex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.99d
TEXLIVE_REV=	21345

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-bibtex

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
