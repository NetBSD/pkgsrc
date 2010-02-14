# $NetBSD: Makefile,v 1.3 2010/02/14 20:18:56 minskim Exp $
# TeX Live Revision 16044

DISTNAME=	bibtex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.99c

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-bibtex

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
