# $NetBSD: Makefile,v 1.7 2012/10/14 21:56:11 minskim Exp $

DISTNAME=	metafont
PKGNAME=	tex-${DISTNAME}-2012
CATEGORIES=	fonts
TEXLIVE_REV=	26689

MAINTAINER=	minskim@NetBSD.org
COMMENT=	METAFONT system for specifying fonts

CONFLICTS+=	teTeX-bin<=3.0nb32
CONFLICTS+=	teTeX-texmf<=3.0nb13
CONFLICTS+=	tex-bin-metapost-[0-9]*
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_FORMATS=	"mf mf-nowin -translate-file=cp227.tcx mf.ini\\n"
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
