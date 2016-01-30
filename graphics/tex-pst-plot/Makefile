# $NetBSD: Makefile,v 1.3 2016/01/30 04:05:53 markd Exp $

DISTNAME=	pst-plot
PKGNAME=	tex-${DISTNAME}-1.70
TEXLIVE_REV=	35025

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Plot data using PSTricks
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
