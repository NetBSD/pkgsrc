# $NetBSD: Makefile,v 1.2 2011/07/28 08:54:58 minskim Exp $

DISTNAME=	metapost
PKGNAME=	tex-${DISTNAME}-1.211
PKGREVISION=	1
TEXLIVE_REV=	17650

MAINTAINER=	minskim@NetBSD.org
COMMENT=	A development of MetaFont for creating graphics

CONFLICTS+=	teTeX-texmf<=3.0nb25
DEPENDS+=	tex-kpathsea>=2009.16044:../../print/tex-kpathsea
DEPENDS+=	web2c>=2009:../../print/web2c

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
