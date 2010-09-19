# $NetBSD: Makefile,v 1.7 2010/09/19 22:53:01 minskim Exp $

DISTNAME=	tetex
PKGNAME=	tex-${DISTNAME}-3.0.19695
TEXLIVE_REV=	19769

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

SUPERSEDES=	tex-bin-tetex<=3.0.12897
CONFLICTS=	tex-bin-tetex<=3.0.12897

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/updmap.cfg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
