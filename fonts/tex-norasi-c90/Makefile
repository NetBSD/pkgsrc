# $NetBSD: Makefile,v 1.3 2015/04/26 01:48:20 markd Exp $

DISTNAME=	norasi-c90
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	30642

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX support (from CJK) for the norasi font

DEPENDS+=	tex-fonts-tlwg>=0.6.1:../../fonts/tex-fonts-tlwg

TEX_MAP_FILES+=	norasi-c90.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
