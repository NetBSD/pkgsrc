# $NetBSD: Makefile,v 1.5 2010/10/24 18:10:39 minskim Exp $

PKGNAME=	tex-${DISTNAME:S/fonts/fonts-base/}
PKGREVISION=	3
COMMENT=	Base UHC fonts for HLaTeX

CONFLICTS+=	tex-hlatex<=1.0.1

TEX_MAP_FILES=	uhc-base.map

UHC_FONTS=	uhc-myoungjo-1.0.tar.gz \
		uhc-gothic-1.0.tar.gz \
		uhc-taza-1.0.tar.gz

.include "../../fonts/tex-uhc-fonts-base/Makefile.common"
