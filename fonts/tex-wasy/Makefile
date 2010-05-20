# $NetBSD: Makefile,v 1.2 2010/05/20 17:52:31 minskim Exp $

DISTNAME=	wasy
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Waldi's symbol fonts

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	wasy.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
