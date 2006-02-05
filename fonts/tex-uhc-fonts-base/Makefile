# $NetBSD: Makefile,v 1.3 2006/02/05 23:09:11 joerg Exp $

PKGNAME=	tex-${DISTNAME:S/fonts/fonts-base/}
PKGREVISION=	1
COMMENT=	Base UHC fonts for HLaTeX

CONFLICTS+=	tex-hlatex<=1.0.1

TEX_FONTMAPS=	uhc-base.map

UHC_FONTS=	uhc-myoungjo-1.0.tar.gz \
		uhc-gothic-1.0.tar.gz \
		uhc-taza-1.0.tar.gz

.include "../../fonts/tex-uhc-fonts-base/Makefile.common"
