# $NetBSD: Makefile,v 1.8 2022/12/21 19:24:51 wiz Exp $

DISTNAME=	tex-gyre
PKGNAME=	tex-${DISTNAME}-2.501
PKGREVISION=	2
TEXLIVE_REV=	48058

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tex-gyre
COMMENT=	TeX Fonts extending freely available URW fonts
LICENSE=	gfsl

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEX_MAP_FILES+=	qag.map
TEX_MAP_FILES+=	qbk.map
TEX_MAP_FILES+=	qcr.map
TEX_MAP_FILES+=	qcs.map
TEX_MAP_FILES+=	qhv.map
TEX_MAP_FILES+=	qpl.map
TEX_MAP_FILES+=	qtm.map
TEX_MAP_FILES+=	qzc.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
