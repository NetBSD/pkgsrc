# $NetBSD: Makefile,v 1.4 2011/02/02 18:23:36 minskim Exp $

DISTNAME=	dvipdfm
PKGNAME=	tex-${DISTNAME}-0.13.2d
PKGREVISION=	3
TEXLIVE_REV=	21248

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipdfm

CONFLICTS+=	tex-bin-dvipdfm-[0-9]*

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/fonts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
