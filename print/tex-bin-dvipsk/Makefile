# $NetBSD: Makefile,v 1.5 2009/04/25 13:51:22 minskim Exp $
# TeX Live Revision 12785

DISTNAME=	bin-dvipsk
PKGNAME=	tex-${DISTNAME}-2008.12785

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipsk

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
