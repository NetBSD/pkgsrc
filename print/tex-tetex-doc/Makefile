# $NetBSD: Makefile,v 1.1.1.1 2010/02/15 00:24:29 minskim Exp $
# TeX Live Revision 16770

DISTNAME=	tetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.0

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-tetex

CONFLICTS+=	teTeX-bin<=3.0nb42

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
