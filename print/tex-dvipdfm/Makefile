# $NetBSD: Makefile,v 1.1.1.1 2010/02/05 19:32:10 minskim Exp $
# TeX Live Revision 16770

DISTNAME=	dvipdfm
PKGNAME=	tex-${DISTNAME}-0.13.2d

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipdfm

CONFLICTS+=	tex-bin-dvipdfm-[0-9]*

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/fonts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
