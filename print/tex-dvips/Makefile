# $NetBSD: Makefile,v 1.6 2010/10/02 21:27:50 minskim Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	19724

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files for a DVI to PostScript driver

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf ${PREFIX}/share/texmf-dist
TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
