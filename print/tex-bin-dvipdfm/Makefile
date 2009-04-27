# $NetBSD: Makefile,v 1.3 2009/04/27 14:55:14 minskim Exp $
# TeX Live Revision 12785

DISTNAME=	bin-dvipdfm
PKGNAME=	tex-${DISTNAME}-0.13.2d.12785

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipdfm

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/fonts

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
