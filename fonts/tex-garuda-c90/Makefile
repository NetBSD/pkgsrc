# $NetBSD: Makefile,v 1.8 2022/04/08 22:58:22 markd Exp $

DISTNAME=	garuda-c90
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	60832

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cjk
COMMENT=	TeX support (from CJK) for the garuda font
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-fonts-tlwg>=0.6.1:../../fonts/tex-fonts-tlwg

TEX_MAP_FILES+=	garuda-c90.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
