# $NetBSD: Makefile,v 1.2 2010/09/24 20:48:15 minskim Exp $

DISTNAME=	dvipdfm
PKGNAME=	tex-${DISTNAME}-0.13.2d
PKGREVISION=	1
TEXLIVE_REV=	19724

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipdfm

CONFLICTS+=	tex-bin-dvipdfm-[0-9]*

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/fonts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
