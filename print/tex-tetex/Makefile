# $NetBSD: Makefile,v 1.10 2011/03/03 22:13:18 minskim Exp $

DISTNAME=	tetex
PKGNAME=	tex-${DISTNAME}-3.0.21248
TEXLIVE_REV=	21308

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

SUPERSEDES=	tex-bin-tetex<=3.0.12897
CONFLICTS=	tex-bin-tetex<=3.0.12897

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
