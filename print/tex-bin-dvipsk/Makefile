# $NetBSD: Makefile,v 1.4 2009/04/24 17:27:28 minskim Exp $
# TeX Live Revision 12497

DISTNAME=	bin-dvipsk
PKGNAME=	tex-${DISTNAME}-2008.12497

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipsk

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
