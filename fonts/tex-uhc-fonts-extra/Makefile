# $NetBSD: Makefile,v 1.2 2005/11/17 00:42:14 minskim Exp $

PKGNAME=	tex-${DISTNAME:S/fonts/fonts-extra/}
COMMENT=	Extra UHC fonts for HLaTeX

DEPENDS+=	tex-uhc-fonts-base>=1.0:../../fonts/tex-uhc-fonts-base

TEX_FONTMAPS=	uhc-extra.map

UHC_FONTS=	uhc-graphic-1.0.tar.gz \
		uhc-gungseo-1.0.tar.gz \
		uhc-shinmun-1.0.tar.gz \
		uhc-pilgi-1.0.tar.gz \
		uhc-pen-1.0.tar.gz \
		uhc-bom-1.0.tar.gz \
		uhc-yetgul-1.0.tar.gz \
		uhc-jamo-1.0.tar.gz \
		uhc-vada-1.0.tar.gz \
		uhc-pilgia-1.0.tar.gz \
		uhc-dinaru-1.0.tar.gz

.include "../../fonts/tex-uhc-fonts-base/Makefile.common"
