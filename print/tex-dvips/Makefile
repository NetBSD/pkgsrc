# $NetBSD: Makefile,v 1.11 2011/03/03 03:16:39 minskim Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2010.21308
TEXLIVE_REV=	21308

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files for a DVI to PostScript driver

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf ${PREFIX}/share/texmf-dist
TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
