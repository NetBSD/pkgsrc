# $NetBSD: Makefile,v 1.6 2010/09/15 15:17:04 minskim Exp $

DISTNAME=	tetex
PKGNAME=	tex-${DISTNAME}-3.0.19695
TEXLIVE_REV=	19724

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

SUPERSEDES=	tex-bin-tetex<=3.0.12897
CONFLICTS=	tex-bin-tetex<=3.0.12897

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
