# $NetBSD: Makefile,v 1.3 2010/02/15 00:08:08 minskim Exp $
# TeX Live Revision 16770

DISTNAME=	pdftex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.40.10

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pdftex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
