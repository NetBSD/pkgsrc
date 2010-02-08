# $NetBSD: Makefile,v 1.2 2010/02/08 05:02:47 minskim Exp $
# TeX Live Revision 16044

DISTNAME=	metafont
PKGNAME=	tex-${DISTNAME}-2009
CATEGORIES=	fonts

MAINTAINER=	minskim@NetBSD.org
COMMENT=	METAFONT font design system

CONFLICTS+=	teTeX-bin<=3.0nb32
CONFLICTS+=	teTeX-texmf<=3.0nb13
CONFLICTS+=	tex-bin-metapost-[0-9]*
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_FORMATS=	"mf mf-nowin -translate-file=cp227.tcx mf.ini"
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
