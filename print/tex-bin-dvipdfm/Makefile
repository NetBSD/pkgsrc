# $NetBSD: Makefile,v 1.4 2009/06/09 22:44:35 minskim Exp $
# TeX Live Revision 12898

DISTNAME=	bin-dvipdfm
PKGNAME=	tex-${DISTNAME}-0.13.2d.12898

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipdfm

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/fonts

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
