# $NetBSD: Makefile,v 1.2 2010/01/28 23:40:42 minskim Exp $
# TeX Live Revision 16770

DISTNAME=	tetex
PKGNAME=	tex-${DISTNAME}-3.0.16770

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

SUPERSEDES=	tex-bin-tetex<=3.0.12897

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
