# $NetBSD: Makefile,v 1.3 2010/01/30 00:26:10 minskim Exp $
# TeX Live Revision 12778

DISTNAME=	bin-metafont
PKGNAME=	tex-${DISTNAME}-2008.12778
PKGREVISION=	2
DIST_SUBDIR=	${PKGNAME_NOREV}nb1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	METAFONT font design system

CONFLICTS+=	teTeX-bin<=3.0nb32
CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	tex-metafont-[0-9]*:../../fonts/tex-metafont
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_FORMAT_NAMES+=	metafont

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
