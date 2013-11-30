# $NetBSD: Makefile,v 1.8 2013/11/30 23:15:17 minskim Exp $

DISTNAME=	metafont
PKGNAME=	tex-${DISTNAME}-2013
CATEGORIES=	fonts
TEXLIVE_REV=	29764

MAINTAINER=	minskim@NetBSD.org
COMMENT=	METAFONT system for specifying fonts

CONFLICTS+=	teTeX-bin<=3.0nb32
CONFLICTS+=	teTeX-texmf<=3.0nb13
CONFLICTS+=	tex-bin-metapost-[0-9]*
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_FORMATS=	"mf mf-nowin -translate-file=cp227.tcx mf.ini\\n"

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
