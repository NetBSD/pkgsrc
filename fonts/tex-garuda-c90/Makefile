# $NetBSD: Makefile,v 1.7 2020/05/10 04:31:45 markd Exp $

DISTNAME=	garuda-c90
PKGNAME=	tex-${DISTNAME}-2015
PKGREVISION=	1
TEXLIVE_REV=	37677

MAINTAINER=	minskim@NetBSD.org
#HOMEPAGE=	http://ctan.org/pkg/garuda-c90
COMMENT=	TeX support (from CJK) for the garuda font

DEPENDS+=	tex-fonts-tlwg>=0.6.1:../../fonts/tex-fonts-tlwg

TEX_MAP_FILES+=	garuda-c90.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
