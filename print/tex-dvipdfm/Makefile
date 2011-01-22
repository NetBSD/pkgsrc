# $NetBSD: Makefile,v 1.3 2011/01/22 20:56:29 minskim Exp $

DISTNAME=	dvipdfm
PKGNAME=	tex-${DISTNAME}-0.13.2d
PKGREVISION=	2
TEXLIVE_REV=	21040

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipdfm

CONFLICTS+=	tex-bin-dvipdfm-[0-9]*

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/fonts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
