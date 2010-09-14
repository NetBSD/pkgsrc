# $NetBSD: Makefile,v 1.3 2010/09/14 00:24:40 minskim Exp $

DISTNAME=	wasy
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Waldi's symbol fonts

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	wasy.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
