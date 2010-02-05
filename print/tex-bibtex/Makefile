# $NetBSD: Makefile,v 1.2 2010/02/05 18:30:30 minskim Exp $
# TeX Live Revision 16044

DISTNAME=	bibtex
PKGNAME=	tex-${DISTNAME}-0.99c
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Reference management software for LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
