# $NetBSD: Makefile,v 1.3 2010/09/14 00:18:09 minskim Exp $

DISTNAME=	bibtex
PKGNAME=	tex-${DISTNAME}-0.99c
TEXLIVE_REV=	18835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Reference management software for LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
