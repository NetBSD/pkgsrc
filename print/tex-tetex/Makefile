# $NetBSD: Makefile,v 1.1.1.1 2010/01/15 20:42:44 minskim Exp $
# TeX Live Revision 16392

DISTNAME=	tetex
PKGNAME=	tex-${DISTNAME}-3.0.16392

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

SUPERSEDES=	tex-bin-tetex<=3.0.12897

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
