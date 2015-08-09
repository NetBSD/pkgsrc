# $NetBSD: Makefile,v 1.4 2015/08/09 06:14:08 markd Exp $

DISTNAME=	norasi-c90
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	37675

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	ttp://ctan.org/pkg/norasi-c90
COMMENT=	TeX support (from CJK) for the norasi font

DEPENDS+=	tex-fonts-tlwg>=0.6.1:../../fonts/tex-fonts-tlwg

TEX_MAP_FILES+=	norasi-c90.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
