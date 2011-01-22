# $NetBSD: Makefile,v 1.8 2011/01/22 21:04:05 minskim Exp $

DISTNAME=	tetex
PKGNAME=	tex-${DISTNAME}-3.0.21040
TEXLIVE_REV=	21040

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

SUPERSEDES=	tex-bin-tetex<=3.0.12897
CONFLICTS=	tex-bin-tetex<=3.0.12897

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
