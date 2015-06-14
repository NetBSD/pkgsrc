# $NetBSD: Makefile,v 1.2 2015/06/14 11:19:59 markd Exp $

DISTNAME=	mflogo-font
PKGNAME=	tex-${DISTNAME}-1.002pl36898
TEXLIVE_REV=	36898

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Metafont logo font

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	mflogo.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
