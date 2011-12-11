# $NetBSD: Makefile,v 1.12 2011/12/11 20:14:24 minskim Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2011
TEXLIVE_REV=	24563

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files for a DVI to PostScript driver

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf ${PREFIX}/share/texmf-dist
TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
