# $NetBSD: Makefile,v 1.3 2010/05/20 17:44:40 minskim Exp $

DISTNAME=	mflogo
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	17487

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX support for MetaFont logo fonts

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	mflogo.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
