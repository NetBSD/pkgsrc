# $NetBSD: Makefile,v 1.3 2010/02/15 20:12:20 minskim Exp $
# TeX Live Revision 16770

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2009.16770

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files for a DVI to PostScript driver

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
