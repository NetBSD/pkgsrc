# $NetBSD: Makefile,v 1.1.1.1 2009/06/07 07:20:23 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	stmaryrd
PKGNAME=	tex-${DISTNAME}-2008.7340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	St Mary Road symbols for theoretical computer science

CONFLICTS+=	teTeX-texmf<=3.0nb15
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex

TEX_MIXEDMAP_FILES+=	stmaryrd.map

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
