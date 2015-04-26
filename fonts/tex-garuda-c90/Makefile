# $NetBSD: Makefile,v 1.3 2015/04/26 01:47:02 markd Exp $

DISTNAME=	garuda-c90
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	30642

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX support (from CJK) for the garuda font

DEPENDS+=	tex-fonts-tlwg>=0.6.1:../../fonts/tex-fonts-tlwg

TEX_MAP_FILES+=	garuda-c90.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
