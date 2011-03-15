# $NetBSD: Makefile,v 1.1.1.1 2011/03/15 18:11:45 minskim Exp $

DISTNAME=	fontname
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	21489

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Scheme for naming fonts in TeX

CONFLICTS=	teTeX-texmf<=3.0nb29

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
