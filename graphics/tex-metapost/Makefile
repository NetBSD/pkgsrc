# $NetBSD: Makefile,v 1.5 2013/12/03 22:44:48 minskim Exp $

DISTNAME=	metapost
PKGNAME=	tex-${DISTNAME}-1.803
TEXLIVE_REV=	31860

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Development of MetaFont for creating graphics

CONFLICTS+=	teTeX-texmf<=3.0nb25
DEPENDS+=	tex-kpathsea>=2009.16044:../../print/tex-kpathsea
DEPENDS+=	web2c>=2011:../../print/web2c

TEX_MAP_FILES=		troff-updmap.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
