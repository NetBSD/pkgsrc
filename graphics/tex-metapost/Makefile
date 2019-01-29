# $NetBSD: Makefile,v 1.9 2019/01/29 06:45:25 markd Exp $

DISTNAME=	metapost
PKGNAME=	tex-${DISTNAME}-1.803pl49482
TEXLIVE_REV=	49482

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Development of MetaFont for creating graphics
LICENSE=	gnu-lgpl-v2

DEPENDS+=	tex-kpathsea>=2009.16044:../../print/tex-kpathsea
DEPENDS+=	web2c>=2011:../../print/web2c

TEX_MAP_FILES=		troff-updmap.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
