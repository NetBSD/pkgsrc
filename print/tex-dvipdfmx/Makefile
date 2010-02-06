# $NetBSD: Makefile,v 1.1.1.1 2010/02/06 00:54:32 minskim Exp $
# TeX Live Revision 16044

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2009

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
