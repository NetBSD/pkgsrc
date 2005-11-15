# $NetBSD: Makefile,v 1.1.1.1 2005/11/15 19:54:16 minskim Exp $

PKGNAME=	tex-${DISTNAME:S/fonts/fonts-base/}
COMMENT=	Base UHC fonts for HLaTeX

CONFLICTS+=	tex-hlatex<=1.0.1

TEXFONTMAPS=	uhc-base.map

UHC_FONTS=	uhc-myoungjo-1.0.tar.gz \
		uhc-gothic-1.0.tar.gz \
		uhc-taza-1.0.tar.gz

.include "../../fonts/tex-uhc-fonts-base/Makefile.common"
