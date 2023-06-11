# $NetBSD: Makefile,v 1.12 2023/06/11 07:19:16 markd Exp $

DISTNAME=	metapost
PKGNAME=	tex-${DISTNAME}-2023
TEXLIVE_REV=	66815

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/metapost
COMMENT=	Development of Metafont for creating graphics
LICENSE=	gnu-lgpl-v2

DEPENDS+=	tex-kpathsea>=2009.16044:../../print/tex-kpathsea
DEPENDS+=	web2c>=2011:../../print/web2c

TEX_MAP_FILES+=	troff-updmap.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
