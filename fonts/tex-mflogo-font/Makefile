# $NetBSD: Makefile,v 1.1 2015/04/26 00:47:41 markd Exp $

DISTNAME=	mflogo-font
PKGNAME=	tex-${DISTNAME}-1.002
TEXLIVE_REV=	35819

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Metafont logo font

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	mflogo.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
