# $NetBSD: Makefile,v 1.5 2017/09/06 10:40:27 wiz Exp $

DISTNAME=	garuda-c90
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	37677

MAINTAINER=	minskim@NetBSD.org
#HOMEPAGE=	http://ctan.org/pkg/garuda-c90
COMMENT=	TeX support (from CJK) for the garuda font

DEPENDS+=	tex-fonts-tlwg>=0.6.1:../../fonts/tex-fonts-tlwg

TEX_MAP_FILES+=	garuda-c90.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
