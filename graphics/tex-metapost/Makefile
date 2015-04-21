# $NetBSD: Makefile,v 1.6 2015/04/21 23:37:00 markd Exp $

DISTNAME=	metapost
PKGNAME=	tex-${DISTNAME}-1.803pl34194
TEXLIVE_REV=	34194

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Development of MetaFont for creating graphics

CONFLICTS+=	teTeX-texmf<=3.0nb25
DEPENDS+=	tex-kpathsea>=2009.16044:../../print/tex-kpathsea
DEPENDS+=	web2c>=2011:../../print/web2c

TEX_MAP_FILES=		troff-updmap.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
