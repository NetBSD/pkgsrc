# $NetBSD: Makefile,v 1.5 2022/04/15 05:04:02 markd Exp $

DISTNAME=	vntex
PKGNAME=	tex-${DISTNAME}-3.2.2
TEXLIVE_REV=	62837

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/vntex
COMMENT=	Support for Vietnamese
# LICENSE=	other-free

TEX_MAP_FILES+=		arevvn.map
TEX_MAP_FILES+=		chartervn.map
TEX_MAP_FILES+=		cmbrightvn.map
TEX_MAP_FILES+=		concretevn.map
TEX_MAP_FILES+=		grotesqvn.map
TEX_MAP_FILES+=		txttvn.map
TEX_MAP_FILES+=		urwvn.map
TEX_MAP_FILES+=		vntopia.map
TEX_MIXEDMAP_FILES+=	vnrother.map
TEX_MIXEDMAP_FILES+=	vnrtext.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
