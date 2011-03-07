# $NetBSD: Makefile,v 1.4 2011/03/07 19:33:18 minskim Exp $

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2010.20279
TEXLIVE_REV=	21369

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipdfmx

DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist
DEPENDS+=	tex-dvipdfmx-def-[0-9]*:../../print/tex-dvipdfmx-def

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/dvipdfmx \
				texmf/fonts/cmap/dvipdfmx/EUC-UCS2 \
				texmf/fonts/map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
