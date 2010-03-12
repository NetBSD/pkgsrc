# $NetBSD: Makefile,v 1.4 2010/03/12 19:38:22 minskim Exp $
# TeX Live Revision 17180

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2009.17180

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files for a DVI to PostScript driver

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
