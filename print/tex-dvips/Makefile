# $NetBSD: Makefile,v 1.8 2010/11/17 19:33:13 minskim Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	3
TEXLIVE_REV=	20445

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files for a DVI to PostScript driver

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf ${PREFIX}/share/texmf-dist
TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
