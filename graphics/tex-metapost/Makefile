# $NetBSD: Makefile,v 1.3 2011/12/15 22:34:40 minskim Exp $

DISTNAME=	metapost
PKGNAME=	tex-${DISTNAME}-1.212
TEXLIVE_REV=	23089

MAINTAINER=	minskim@NetBSD.org
COMMENT=	A development of MetaFont for creating graphics

CONFLICTS+=	teTeX-texmf<=3.0nb25
DEPENDS+=	tex-kpathsea>=2009.16044:../../print/tex-kpathsea
DEPENDS+=	web2c>=2011:../../print/web2c

TEX_MAP_FILES=		troff-updmap.map
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
