# $NetBSD: Makefile,v 1.3 2010/05/06 01:47:41 reed Exp $
# TeX Live Revision 16770

DISTNAME=	tetex
PKGNAME=	tex-${DISTNAME}-3.0.16770

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

SUPERSEDES=	tex-bin-tetex<=3.0.12897
CONFLICTS=	tex-bin-tetex<=3.0.12897

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
