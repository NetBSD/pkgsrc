# $NetBSD: Makefile,v 1.4 2006/04/07 04:47:20 minskim Exp $

PKGNAME=	tex-${DISTNAME:S/fonts/fonts-base/}
PKGREVISION=	2
COMMENT=	Base UHC fonts for HLaTeX

CONFLICTS+=	tex-hlatex<=1.0.1

TEX_FONTMAPS=	uhc-base.map

UHC_FONTS=	uhc-myoungjo-1.0.tar.gz \
		uhc-gothic-1.0.tar.gz \
		uhc-taza-1.0.tar.gz

.include "../../fonts/tex-uhc-fonts-base/Makefile.common"
