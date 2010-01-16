# $NetBSD: Makefile,v 1.2 2010/01/16 03:42:22 minskim Exp $
# TeX Live Revision 16376

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2009.16376

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files for a DVI to PostScript driver

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
