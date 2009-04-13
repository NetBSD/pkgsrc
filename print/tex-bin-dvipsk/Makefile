# $NetBSD: Makefile,v 1.3 2009/04/13 00:13:03 minskim Exp $
# TeX Live Revision 12172

DISTNAME=	bin-dvipsk
PKGNAME=	tex-${DISTNAME}-2008.12172

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipsk

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
