# $NetBSD: Makefile,v 1.8 2022/04/13 10:37:20 wiz Exp $

DISTNAME=	norasi-c90
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	60831

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cjk
COMMENT=	TeX support (from CJK) for the norasi font
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-fonts-tlwg-[0-9]*:../../fonts/tex-fonts-tlwg

TEX_MAP_FILES+=	norasi-c90.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
