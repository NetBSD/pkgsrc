# $NetBSD: Makefile,v 1.6 2011/04/13 01:48:55 minskim Exp $

DISTNAME=	metafont
PKGNAME=	tex-${DISTNAME}-2009
PKGREVISION=	1
CATEGORIES=	fonts
TEXLIVE_REV=	21566

MAINTAINER=	minskim@NetBSD.org
COMMENT=	METAFONT font design system

CONFLICTS+=	teTeX-bin<=3.0nb32
CONFLICTS+=	teTeX-texmf<=3.0nb13
CONFLICTS+=	tex-bin-metapost-[0-9]*
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_FORMATS=	"mf mf-nowin -translate-file=cp227.tcx mf.ini\\n"
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
