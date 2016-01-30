# $NetBSD: Makefile,v 1.2 2016/01/30 04:56:43 markd Exp $

DISTNAME=	manfnt-font
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	35799

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Font for LaTeX support for the TeX book symbols
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	manfnt.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
